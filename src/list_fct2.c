/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:35:56 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/20 12:35:59 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			get_nb_elm(t_clist *list)
{
	int		count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}

t_clist		*copy_list(t_clist *list)
{
	t_clist	*copy;

	copy = NULL;
	while (list)
	{
		if (add2list(&copy, list->nb))
			return (NULL);
		list = list->next;
	}
	return (copy);
}
