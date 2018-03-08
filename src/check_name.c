/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:13:54 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/08 19:21:38 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_name(t_vertex *vertex)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (++i <= vertex[0].x)
	{
		tmp = vertex[i].name;
		if (ft_strchr(tmp, '-') || tmp[0] == 'L')
			return (1);
		j = i;
		while (++j <= vertex[0].x)
			if (ft_strequ(tmp, vertex[j].name))
				return (1);
	}
	return (0);
}
