/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:40:22 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/11 14:27:33 by jjauzion         ###   ########.fr       */
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
		vertex[i].ant = 0;
	}
	vertex[0].name = ft_strdup("vertex[0].x = nb_of_vertex ; .y = nb_of_ants");
	vertex[0].y = -1;
	return (vertex);
}

t_clist		**init_adj_list(int size)
{
	int			i;
	t_clist		**adj_list;

	if (size <= 0)
		return (NULL);
	if (!(adj_list = (t_clist**)malloc(sizeof(t_clist*) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		adj_list[i] = NULL;
	return (adj_list);
}

int			**init_path_data_tab(int size)
{
	int		**path_data;
	int		i;

	if (!(path_data = (int**)malloc(sizeof(int*) * 3)))
		return (NULL);
	if (!(path_data[0] = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	if (!(path_data[1] = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	if (!(path_data[2] = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		path_data[0][i] = INT_MAX;
		path_data[1][i] = 0;
		path_data[2][i] = -1;
	}
	path_data[0][0] = 0;
	return (path_data);
}
