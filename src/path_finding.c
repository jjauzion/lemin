/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:17:03 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/10 19:20:19 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			add_path(int **path, int nb_of_path, int **path_data)
{
	int	i;
	int	preceding;
/*
	if (nb_of_path > PATH_DEF_NB)
		realloc_path(path, nb_of_path);
*/
	if (!(path[nb_of_path - 1] = (int*)malloc(sizeof(int) * (path_data[0][1] + 2))))
		return (1);
	i = path_data[0][1];
	path[nb_of_path - 1][i + 1] = -1;
	path[nb_of_path - 1][i] = 1;
	preceding = path_data[2][1];
	while (--i >= 0)
	{
		path[nb_of_path - 1][i] = preceding;
		preceding = path_data[2][preceding];
	}
	path[nb_of_path] = NULL;
	return (0);
}

static void	remove_path_from_graph(int *path, t_clist **adj_list, int nb_vertex)
{
	int	i;
	int	j;

	i = -1;
	while (++i < nb_vertex)
	{
		j = 0;
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

int			path_finding(int **path, t_vertex *vertex, t_clist **adj_list)
{
/*
**	**path_data:
**	[0][i] : distance from vertex i to start
**	[1][i] : visited (1) or not (0)
**	[2][i] : preceding vertex of vertex i
*/
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
