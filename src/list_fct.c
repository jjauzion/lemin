/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:48:58 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/10 18:14:25 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_clist		*new_elm(int data)
{
	t_clist	*elm;

	if (!(elm = (t_clist*)malloc(sizeof(t_clist))))
		return (NULL);
	elm->nb = data;
	elm->next = NULL;
	return (elm);
}

int			add2list(t_clist **list, int data)
{
	t_clist	*elm;

	if (!(elm = new_elm(data)))
		return (1);
	elm->next = *list;
	*list = elm;
	return (0);
}

void		remove_elm(t_clist **list, int data)
{
	t_clist	*ptr1;
	t_clist	*ptr2;

	if (!list || !(*list))
		return ;
	if ((*list)->nb == data)
	{
		ptr1 = (*list)->next;
		free(*list);
		*list = ptr1;
		return ;
	}
	ptr1 = *list;
	ptr2 = ptr1->next;
	while (ptr2 && ptr2->nb != data)
	{
		ptr1 = ptr2;
		ptr2 = ptr2->next;
	}
	if (!ptr2)
		return ;
	ptr1->next = ptr2->next;
	free(ptr2);
}

void		free_list(t_clist **list)
{
	t_clist *ptr;

	if (!list)
		return ;
	while (*list)
	{
		ptr = (*list)->next;
		free(*list);
		*list = ptr;
	}
}
