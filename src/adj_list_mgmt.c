/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_list_mgmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:49:18 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/16 18:21:27 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			remove_start_link(int link_id, t_clist **list)
{
	t_clist	*ptr1;
	t_clist	*ptr2;
	int		del_link;
	int		i;

	if (!list || !(*list) || link_id < 0)
		return (-1);
	ptr1 = *list;
	ptr2 = ptr1->next;
	if (link_id == 0)
	{
		del_link = (*list)->nb;
		free(*list);
		*list = ptr2;
		return (del_link);
	}
	i = 0;
	while (++i < link_id)
	{
		ptr1 = ptr2;
		ptr2 = ptr2->next;
	}
	del_link = ptr2->nb;
	ptr1->next = ptr2->next;
	free(ptr2);
	return (del_link);
}

t_clist		**copy_adj_list(t_clist **list, int size)
{
	t_clist	**copy;
	int		i;

	if (!(copy = init_adj_list(size)))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		copy[i] = copy_list(list[i]);
	}
	return (copy);
}
