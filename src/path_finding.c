/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:17:03 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/16 20:10:36 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			add_path(int **path, int nb_of_path, int **path_data)
{
	int	i;
	int	preceding;

/*	if (nb_of_path > PATH_DEF_NB)
		realloc_path(path, nb_of_path);*/
	if (!(path[nb_of_path - 1] = (int*)malloc(sizeof(int) * (path_data[0][1] + 2))))
		return (1);
	i = path_data[0][1];
	path[nb_of_path - 1][0] = i;
	path[nb_of_path - 1][i + 1] = 1;
	preceding = path_data[2][1];
	while (i > 0)
	{
		path[nb_of_path - 1][i] = preceding;
		preceding = path_data[2][preceding];
		i--;
	}
	path[nb_of_path] = NULL;
	return (0);
}

static void	remove_path_from_graph(int *path, t_clist **adj_list, int nb_vertex)
{
	int	i;
	int	j;

	if (path[2] == 1)
	{
		remove_elm(&adj_list[0], 1);
		return ;
	}
	i = -1;
	while (++i < nb_vertex)
	{
		j = 1;
		while (path[++j] != 1)
		{
			if (i == path[j])
				free_list(&adj_list[i]);
			else
				remove_elm(&adj_list[i], path[j]);
		}
	}
}

static void	reinit_path_data(int **path_data, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		path_data[0][i] = INT_MAX;
		path_data[1][i] = 0;
		path_data[2][i] = -1;
	}
	path_data[0][0] = 0;
}

static int	copy_path(int **dest, int **src, int nb_of_path)
{
	int	i;
	int	j;

/*	if (nb_of_path > PATH_DEF_NB)
		realloc_path(path, nb_of_path);*/
	i = -1;
	while (++i < nb_of_path)
	{
		if (!(dest[i] = (int*)malloc(sizeof(int) * (src[i][0] + 2))))
			return (1);
		j = -1;
		while (++j <= src[i][0] + 1)
		{
			dest[i][j] = src[i][j];
		}
	}
	dest[nb_of_path] = NULL;
	return (0);
}

/*
**	**path_data:
**	[0][i] : distance from vertex i to start
**	[1][i] : visited (1) or not (0)
**	[2][i] : preceding vertex of vertex i
**
**	soltuion:
**	sol[i].path			= list of path for solution i
**	sol[i].nb_of_path	= nb of path for solution i
**	sol[n].nb_of_path	= -1 with n = nb of link on the start node
*/

int			path_finding(int **path, t_vertex *vertex, t_clist **adj_list)
{
	int		**path_data;
	t_sol	*solution;
	int		nb_sol;
	t_clist	**tmp_list;
	int		i;
	int		link;
	int		*tmp;

	nb_sol = get_nb_elm(adj_list[0]);
	solution = init_solution(nb_sol);
	path_data = init_path_data_tab(vertex[0].x);
	if (!path_data || !solution)
		return (0);
	i = -1;
	while (++i < nb_sol)
	{
		if (!(tmp_list = copy_adj_list(adj_list, vertex[0].x)))
			return (0);
		solution[i].nb_of_path = 0;
		link = remove_start_link(i, tmp_list);
		while (djikstra(path_data, vertex, tmp_list) > 0)
		{
			solution[i].nb_of_path++;
			if (add_path(solution[i].path, solution[i].nb_of_path, path_data))
				return (0);
			remove_path_from_graph(solution[i].path[solution[i].nb_of_path - 1], tmp_list, vertex[0].x);
			reinit_path_data(path_data, vertex[0].x);
		}
		reinit_path_data(path_data, vertex[0].x);
		add2list(&tmp_list[0], link);
		if (djikstra(path_data, vertex, tmp_list) > 0)
		{
			solution[i].nb_of_path++;
			if (add_path(solution[i].path, solution[i].nb_of_path, path_data))
				return (0);
		}
		if (solution[i].path[solution[i].nb_of_path - 1][0] < solution[i].path[0][0])
		{
			tmp = solution[i].path[0];
			solution[i].path[0] = solution[i].path[solution[i].nb_of_path - 1];
			solution[i].path[solution[i].nb_of_path - 1] = tmp;
		}
		reinit_path_data(path_data, vertex[0].x);
		free_adj_list(&tmp_list, vertex[0].x);
	}
//	i = find_best_solution(solution, nb_of_ant);
	i = 0;
	if (copy_path(path, solution[i].path, solution[i].nb_of_path))
		return (0);
	i = solution[i].nb_of_path;
	free_solution(&solution);
	free_int_matrix(&path_data, 3);
	return (i);
}

/*
int			path_finding(int **path, t_vertex *vertex, t_clist **adj_list)
{
	int		**path_data;
	int		nb_of_path;

	if (!(path_data = init_path_data_tab(vertex[0].x)))
		return (0);
	nb_of_path = 0;
	while (djikstra(path_data, vertex, adj_list) > 0)
	{
		nb_of_path++;
		if (add_path(path, nb_of_path, path_data))
			return (0);
		remove_path_from_graph(path[nb_of_path - 1], adj_list, vertex[0].x);
		reinit_path_data(path_data, vertex[0].x);
	}
	free_int_matrix(&path_data, 3);
	return (nb_of_path);
}
*/
