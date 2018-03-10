/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:48:58 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/10 12:32:23 by jjauzion         ###   ########.fr       */
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
