/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:31:47 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/08 19:22:58 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_vertex	*vertex;
	t_clist		*adj_list;
	int			i;

	if (parse(&vertex, &adj_list) || check_name(vertex))
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

	return (0);
}
