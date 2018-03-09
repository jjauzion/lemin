/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:31:47 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/09 18:29:14 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_vertex	*vertex;
	t_clist		**adj_list;
	int			i;
//	t_paths		path;

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
/*	if (path_finding(&path, adj_list, vertex) == 0)
	{
		ft_printf("no path to exit, the poor ants die trappred in their maze :(\n");
		return (1);
	}*/
//	run_ants_run();
	return (0);
}
