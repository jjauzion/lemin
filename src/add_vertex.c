/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:17:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/20 13:09:15 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	realloc_vertex(int index, int *max_nb_vertex, t_vertex **vertex)
{
	if (index + 3 > *max_nb_vertex)
	{
		if (!(*vertex = (t_vertex*)ft_realloc((void*)vertex, sizeof(t_vertex) *
						(*max_nb_vertex + 1), sizeof(t_vertex) *
						VERTEX_DEF_NB)))
			return (1);
		(*max_nb_vertex) += VERTEX_DEF_NB;
	}
	return (0);
}

static int	get_index(int option, int *index)
{
	int	i;

	if (option == OPT_START)
		i = 1;
	else if (option == OPT_END)
		i = 2;
	else
	{
		i = *index + 3;
		(*index)++;
	}
	return (i);
}

static void	set_vertex(char *name, int x, int y, t_vertex *vertex)
{
	vertex->name = ft_strdup(name);
	vertex->x = x;
	vertex->y = y;
}

int			add_vertex(char **word, t_vertex **vertex, int option)
{
	static int	max_nb_vertex = VERTEX_DEF_NB;
	static int	index = 0;
	int			i;
	intmax_t	x;
	intmax_t	y;

	if (option == OPT_LINK || realloc_vertex(index, &max_nb_vertex, vertex))
		return (-1);
	i = 0;
	while (word[i])
		i++;
	if (i != 3 || !ft_isnumber(word[1]) || !ft_isnumber(word[2]))
		return (-1);
	x = ft_atoim(word[1]);
	y = ft_atoim(word[2]);
	if (x > INT_MAX || x < INT_MIN || y > INT_MAX || y < INT_MIN)
		return (-1);
	if (check_name(*vertex, word[0]))
		return (-1);
	i = get_index(option, &index);
	if ((*vertex)[i].name != NULL)
		return (-1);
	set_vertex(word[0], (int)x, (int)y, &(*vertex)[i]);
	(*vertex)[0].x++;
	return (0);
}
