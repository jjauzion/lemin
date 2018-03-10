/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:31:47 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/10 20:00:12 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	*vertex:
**	[0].x =	nb of vertex in the graph
**	[0].y =	nb of ants
**	[1] =	start vertex
**	[2] =	exit vertex
**	[n] =	other vertex
**
**	**adj_list:
**	[vertex id] -> [connected vertex id | pointer to next] -> ... -> NULL
**	e.g.:
**	[0] -> [2 | next] -> [1 | next] -> NULL
**	[n - 1] -> ... -> NULL
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
	int			i;
	int			**path;
	int			nb_of_path;

	if (parse(&vertex, &adj_list) || vertex[0].y < 0)
	{
		ft_printf("ERROR\n");
		return (1);
	}
i = -1;
while (++i <= vertex[0].x)
{
	ft_printf("vertex[%d].name = |%s|\n", i, vertex[i].name);
	ft_printf("vertex[%d].x = |%d|\n", i, vertex[i].x);
	ft_printf("vertex[%d].y = |%d|\n", i, vertex[i].y);
}
print_adj_list(adj_list, vertex[0].x);
	if (!(path = (int**)malloc(sizeof(int*) * (PATH_DEF_NB + 1))))
		return (1);
	if ((nb_of_path = path_finding(path, vertex, adj_list)) <= 0)
	{
		ft_printf("No path found :( poor ants die trapped in their maze...\n");
		return (1);
	}
	print_path(path);

//	run_ants_run(path, nb_of_path, vertex);
	free_adj_list(&adj_list, vertex[0].x);
	free_int_matrix(&path, nb_of_path);
	free_vertex(&vertex);
	return (0);
}
