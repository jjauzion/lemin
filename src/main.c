/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:31:47 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/19 14:18:44 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	*vertex:
**	[0].x =		nb of vertex in the graph
**	[0].y =		nb of ants
**	[1] =		start vertex
**	[2] =		exit vertex
**	[1].ant =	nb of ant on start node
**	[2].ant =	nb of ant on end node
**	[i].name =	vertex i name (with i = node id + 1)
**	[i].x =		i vertex x coordinate
**	[i].y =		i vertex y coordinate
**	[i].ant =	ant id on vertex i (0 if no ant on node)
**
**	**adj_list:
**	[i] -> pointer to list of all nodes connected to node i (with i = node id)
**	[0] -> pointer to list of all nodes connected to START node
**	[1]	-> pointer to list of all nodes connected to END node
**	[n] -> pointer to list of all nodes connected to last node (with n = nb of vertex - 1)
**
**	**path:
**	[i][0]		= lenght (l) of path i (l = nb of nodes on the path - 1)
**	[i][1]		= start node
**	[i][...]	= nodes on the path
**	[i][l + 1]	= end node
*/

int		main(void)
{
	t_vertex	*vertex;
	t_clist		**adj_list;
	int			**path;
	int			nb_of_path;

	parse(&vertex, &adj_list);
	if (vertex[0].y < 0 || vertex[1].name == NULL || vertex[2].name == NULL || !adj_list)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	if (!(path = (int**)malloc(sizeof(int*) * (PATH_DEF_NB + 1))))
		return (1);
	print_maze(NULL);
	if ((nb_of_path = path_finding(path, vertex, adj_list)) <= 0)
	{
		ft_printf("ERROR: No path found\n");
		return (1);
	}
//print_path(path, vertex);
	run_ants_run(path, nb_of_path, vertex);
	free_adj_list(&adj_list, vertex[0].x);
	free_int_matrix(&path, nb_of_path);
	free_vertex(&vertex);
	return (0);
}
