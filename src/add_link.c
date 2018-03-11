/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:24:14 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/11 16:47:30 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	link_is_new(t_clist **adj_list, int v1, int v2)
{
	t_clist	*ptr;

	ptr = adj_list[v1];
	while (ptr)
	{
		if (ptr->nb == v2)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int			add_link(char *line, t_vertex *vertex, t_clist ***adj_list)
{
	static char	init = 1;
	char		**word;
	int			i;
	int			vertex1;
	int			vertex2;

	if (init)
	{
		check_name(vertex);
		*adj_list = init_adj_list(vertex[0].x);
		init = 0;
	}
	word = ft_strsplit(line, '-');
	if (!(*adj_list) || !word || !word[0] || !word[1] || word[2] != 0)
	{
		free_word(&word);
		return (-1);
	}
	i = 0;
	vertex1 = -1;
	vertex2 = -1;
	while (++i <= vertex[0].x && (vertex1 < 0 || vertex2 < 0))
	{
		if (ft_strequ(vertex[i].name, word[0]))
			vertex1 = i - 1;
		else if (ft_strequ(vertex[i].name, word[1]))
			vertex2 = i - 1;
	}
	if (vertex1 < 0 || vertex2 < 0)
	{
		free_word(&word);
		return (-1);
	}
	if (link_is_new(*adj_list, vertex1, vertex2))
		if (add2list(&(*adj_list)[vertex1], vertex2) ||	add2list(&(*adj_list)[vertex2], vertex1))
			return (-1);
	free_word(&word);
	return (OPT_LINK);
}
