/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:17:03 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/20 17:01:19 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	**path_data:
**	[0][i] : distance from vertex i to start
**	[1][i] : visited (1) or not (0)
**	[2][i] : preceding vertex of vertex i
**
**	soltuion:
**	sol[i].path			= path matrix for solution i
**	sol[i].nb_of_path	= nb of path for solution i
**	sol[n].nb_of_path	= -1 with n = nb of link on the start node
*/

static int	djikstra_1st_loop(int **path_data, t_vertex *vertex,
		t_clist **tmp_list, t_sol *solution)
{
	int	index;

	while (djikstra(path_data, vertex, tmp_list) > 0)
	{
		solution->nb_of_path++;
		if ((index = add_path(solution->path, solution->nb_of_path, path_data))
				< 0)
			return (1);
		remove_path_from_graph(solution->path[index], tmp_list, vertex[0].x);
		reinit_path_data(path_data, vertex[0].x);
	}
	return (0);
}

static int	djikstra_2nd(int **path_data, t_vertex *vertex,
		t_clist **tmp_list, t_sol *solution)
{
	if (djikstra(path_data, vertex, tmp_list) > 0)
	{
		solution->nb_of_path++;
		if (add_path(solution->path, solution->nb_of_path, path_data) < 0)
			return (1);
	}
	return (0);
}

static int	solution_finding(int **path_data, t_clist **adj_list,
		t_vertex *vertex, t_sol *solution)
{
	int			i;
	int			nb_sol;
	t_clist		**tmp_list;
	int			link;

	nb_sol = get_nb_elm(adj_list[0]);
	i = -1;
	while (++i < nb_sol)
	{
		if (!(tmp_list = copy_adj_list(adj_list, vertex[0].x)))
			return (0);
		solution[i].nb_of_path = 0;
		link = remove_start_link(i, tmp_list);
		if (djikstra_1st_loop(path_data, vertex, tmp_list, &solution[i]))
			return (0);
		reinit_path_data(path_data, vertex[0].x);
		add2list(&tmp_list[0], link);
		if (djikstra_2nd(path_data, vertex, tmp_list, &solution[i]))
			return (0);
		reinit_path_data(path_data, vertex[0].x);
		free_adj_list(&tmp_list, vertex[0].x);
	}
	return (nb_sol);
}

int			path_finding(int **path, t_vertex *vertex, t_clist **adj_list)
{
	int		**path_data;
	t_sol	*solution;
	int		i;
	int		nb_sol;

	nb_sol = get_nb_elm(adj_list[0]);
	solution = init_solution(nb_sol);
	path_data = init_path_data_tab(vertex[0].x);
	if (!path_data || !solution)
		return (0);
	if ((nb_sol = solution_finding(path_data, adj_list, vertex, solution)) <= 0)
		return (0);
	i = find_best_solution(solution, vertex[0].y);
	if (i < 0 || copy_path(path, solution[i].path, solution[i].nb_of_path))
		return (0);
	i = solution[i].nb_of_path;
	free_solution(&solution);
	free_int_matrix(&path_data, 3);
	return (i);
}
