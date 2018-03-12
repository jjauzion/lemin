/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:17:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/12 14:59:40 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		add_vertex(char **word, t_vertex **vertex, int option)
{
	static int	max_nb_of_vertex = VERTEX_DEF_NB;
	static int	index = 0;
	int			i;
	intmax_t	x;
	intmax_t	y;

	if (option == OPT_LINK)
		return (-1);
	if (index + 3 > max_nb_of_vertex)
	{
		if (!(*vertex = (t_vertex*)ft_realloc((void*)vertex, sizeof(t_vertex) *
						(max_nb_of_vertex + 1), sizeof(t_vertex) *
						VERTEX_DEF_NB)))
			return (-1);
		max_nb_of_vertex += VERTEX_DEF_NB;
	}
	i = 0;
	while(word[i])
		i++;
	if (i != 3 || !ft_isnumber(word[1]) || !ft_isnumber(word[2]))
		return (-1);
	x = ft_atoim(word[1]);
	y = ft_atoim(word[2]);
	if (x > INT_MAX || x < INT_MIN || y > INT_MAX || y < INT_MIN)
		return (-1);
	if (check_name(*vertex, word[0]))
		return (-1);
	if (option == OPT_START)
		i = 1;
	else if (option == OPT_END)
		i = 2;
	else
	{
		i = index + 3;
		index++;
	}
	if ((*vertex)[i].name != NULL)
		return (-1);
	(*vertex)[i].name = ft_strdup(word[0]);
	(*vertex)[i].x = (int)x;
	(*vertex)[i].y = (int)y;
	(*vertex)[0].x++;
	return (0);
}
