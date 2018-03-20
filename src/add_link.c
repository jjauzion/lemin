/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:24:14 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/20 13:51:42 by jjauzion         ###   ########.fr       */
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

static void	first_call(t_clist ***adj_list, int size, char *init)
{
	if (*init)
	{
		*adj_list = init_adj_list(size);
		*init = 0;
	}
}

static char	**get_arg(char *line)
{
	char	**word;

	word = ft_strsplit(line, '-');
	if (!word || !word[0] || !word[1] || word[2] != 0)
	{
		free_word(&word);
		return (NULL);
	}
	return (word);
}

static void	get_vertex_id(t_vertex *vertex, char **word, int *id1, int *id2)
{
	int			i;

	i = 0;
	*id1 = -1;
	*id2 = -1;
	while (++i <= vertex[0].x && (*id1 < 0 || *id2 < 0))
	{
		if (ft_strequ(vertex[i].name, word[0]))
			*id1 = i - 1;
		else if (ft_strequ(vertex[i].name, word[1]))
			*id2 = i - 1;
	}
}

int			add_link(char *line, t_vertex *vertex, t_clist ***adj_list)
{
	static char	init = 1;
	char		**word;
	int			vertex1;
	int			vertex2;

	first_call(adj_list, vertex[0].x, &init);
	if (!(*adj_list) || !(word = get_arg(line)))
		return (-1);
	get_vertex_id(vertex, word, &vertex1, &vertex2);
	if (vertex1 < 0 || vertex2 < 0)
	{
		free_word(&word);
		return (-1);
	}
	if (link_is_new(*adj_list, vertex1, vertex2))
		if (add2list(&(*adj_list)[vertex1], vertex2) ||
				add2list(&(*adj_list)[vertex2], vertex1))
			return (-1);
	free_word(&word);
	return (OPT_LINK);
}
