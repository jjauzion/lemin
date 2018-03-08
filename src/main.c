/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:31:47 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/08 14:56:58 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_vertex	*vertex;
	t_clist		*adj_list;
	int			nb_vertex;

	if (parse(&vertex, &adj_list))
	{
		ft_printf("ERROR\n");
		return (1);
	}
	return (0);
}
