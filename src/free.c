/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:20:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/16 18:46:08 by jjauzion         ###   ########.fr       */
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

	i = -1;
	while (++i < size)
		free_list(&(*adj_list)[i]);
	free(*adj_list);
}

void		free_int_matrix(int ***matrix, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free((*matrix)[i]);
	free(*matrix);
}

void		free_solution(t_sol **sol)
{
	int		i;

	i = -1;
	while ((*sol)[++i].nb_of_path >= 0)
		free_int_matrix(&(*sol)[i].path, (*sol)[i].nb_of_path);
	free(*sol);
}
