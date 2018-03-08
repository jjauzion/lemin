/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:40:22 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/08 16:41:11 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_vertex	*init_vertex(int size)
{
	t_vertex	*vertex;
	int			i;

	if (!(vertex = (t_vertex*)malloc(sizeof(t_vertex) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i <= size)
	{
		vertex[i].name = NULL;
		vertex[i].x = 0;
		vertex[i].y = 0;
	}
	vertex[0].name = ft_strdup("nb_of_vertex");
	return (vertex);
}
