/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:16:17 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/20 17:06:19 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			sort_path(int **path, int nb_of_path, int path_length)
{
	int	i;
	int	position;

	position = 0;
	while (position < nb_of_path - 1 && path_length > path[position][0])
		position++;
	i = nb_of_path - 1;
	while (i > position)
	{
		path[i] = path[i - 1];
		i--;
	}
	return (position);
}

int			add_path(int **path, int nb_of_path, int **path_data)
{
	int	i;
	int	preceding;
	int	position;

	if (nb_of_path > PATH_DEF_NB)
		return (-1);
	i = path_data[0][1];
	position = sort_path(path, nb_of_path, i);
	if (!(path[position] = (int*)malloc(sizeof(int) * (path_data[0][1] + 2))))
		return (-1);
	path[position][0] = i;
	path[position][i + 1] = 1;
	preceding = path_data[2][1];
	while (i > 0)
	{
		path[position][i] = preceding;
		preceding = path_data[2][preceding];
		i--;
	}
	path[nb_of_path] = NULL;
	return (position);
}

void		remove_path_from_graph(int *path, t_clist **adj_list, int nb_vertex)
{
	int	i;
	int	j;

	if (path[2] == 1)
	{
		remove_elm(&adj_list[0], 1);
		return ;
	}
	i = -1;
	while (++i < nb_vertex)
	{
		j = 1;
		while (path[++j] != 1)
		{
			if (i == path[j])
				free_list(&adj_list[i]);
			else
				remove_elm(&adj_list[i], path[j]);
		}
	}
}

void		reinit_path_data(int **path_data, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		path_data[0][i] = INT_MAX;
		path_data[1][i] = 0;
		path_data[2][i] = -1;
	}
	path_data[0][0] = 0;
}

int			copy_path(int **dest, int **src, int nb_of_path)
{
	int	i;
	int	j;

	if (nb_of_path > PATH_DEF_NB)
		return (1);
	i = -1;
	while (++i < nb_of_path)
	{
		if (!(dest[i] = (int*)malloc(sizeof(int) * (src[i][0] + 2))))
			return (1);
		j = -1;
		while (++j <= src[i][0] + 1)
		{
			dest[i][j] = src[i][j];
		}
	}
	dest[nb_of_path] = NULL;
	return (0);
}
