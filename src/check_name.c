/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:13:54 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/12 15:03:39 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_name(t_vertex *vertex, char *name)
{
	int		i;

	if (ft_strchr(name, '-') || name[0] == 'L')
		return (1);
	i = -1;
	while (vertex[++i].name)
	{
		if (ft_strequ(name, vertex[i].name))
			return (1);
	}
	return (0);
}
