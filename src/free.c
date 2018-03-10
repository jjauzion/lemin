/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:20:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/10 10:27:23 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_word(char ***word)
{
	int	i;

	i = -1;
	while ((*word)[++i])
		free((*word)[i]);
	free(*word);
}

void		free_vertex(t_vertex **vertex)
{
	int	size;
	int	i;

	size = (*vertex)[0].x;
	i = -1;
	while (++i <= size)
		ft_strdel(&(*vertex)[i].name);
	free(*vertex);
	*vertex = NULL;
}

void		free_adj_list(t_clist ***adj_list, int size)
{
	int		i;
	t_clist	*ptr;

	i = -1;
	while (++i < size)
	{
		while ((*adj_list)[i])
		{
			ptr = (*adj_list)[i];
			free((*adj_list)[i]);
			(*adj_list)[i] = ptr->next;
		}
	}
	free(*adj_list);
}
