/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:48:58 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/09 15:08:52 by jjauzion         ###   ########.fr       */
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

void		print_adj_list(t_clist **list, int size)
{
	int		i;
	t_clist	*ptr;

	if (!list)
		return ;
	i = -1;
	while (++i < size)
	{
		ft_printf("%3d: |", i);
		ptr = list[i];
		while (ptr)
		{
			ft_printf("%d", ptr->nb);
			if (ptr->next)
				ft_printf("-");
			ptr = ptr->next;
		}
		ft_printf("|\n");
	}
}
