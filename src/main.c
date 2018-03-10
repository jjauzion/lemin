/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:31:47 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/10 13:27:49 by jjauzion         ###   ########.fr       */
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
**	[0] -> [2 | next] -> [1 | next] -> NULL
**	[n - 1] -> ... -> NULL
*/

int		main(void)
{
	t_vertex	*vertex;
	t_clist		**adj_list;
	int			i;
	t_clist		**path;

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
	if (path_finding(&path, vertex, adj_list))
		return (1);
	print_adj_list(path, 1);

//	run_ants_run();
	free_adj_list(&adj_list, vertex[0].x);
	free_vertex(&vertex);
	return (0);
}
