/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djikstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:28:40 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/16 19:58:41 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		get_closest_node(int **path_data, int size)
{
	int	i;
	int	min;
	int	index;

	index = -1;
	min = INT_MAX;
	i = -1;
	while (++i < size)
	{
		if (path_data[0][i] < min && path_data[1][i] == 0)
		{
			min = path_data[0][i];
			index = i;
		}
	}
	return (index);
}

int				djikstra(int **path_data, t_vertex *v, t_clist **adj_list)
{
	int		current_node;
	t_clist	*ptr;
	int		next;

	current_node = get_closest_node(path_data, v[0].x);
	if (current_node == 1)
		return (1);
	if (current_node < 0)
		return (0);
	path_data[1][current_node] = 1;
	ptr = adj_list[current_node];
	while (ptr)
	{
		next = ptr->nb;
		if (path_data[1][next] == 0)
		{
			if (path_data[0][next] > path_data[0][current_node] + 1)
			{
				path_data[0][next] = path_data[0][current_node] + 1;
				path_data[2][next] = current_node;
			}
		}
		ptr = ptr->next;
	}
	return (djikstra(path_data, v, adj_list));
}
