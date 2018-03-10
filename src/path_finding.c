/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:17:03 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/10 15:01:16 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			save_path(t_clist ***path, int nb_of_path, int **path_data)
{
	int	i;
	int	preceding;

	if (!(*path = init_adj_list(nb_of_path + 1)))
		return (1);
	i = -1;
	while (++i < nb_of_path)
	{
		if (add2list(&(*path)[i], 1))
			return (1);
		preceding = path_data[2][1];
		if (add2list(&(*path)[i], preceding))
			return (1);
		while (preceding != 0)
		{
			preceding = path_data[2][preceding];
			if (add2list(&(*path)[i], preceding))
				return (1);
		}
	}
	return (0);
}

/*
**	**path_data:
**	[0][i] : distance from vertex i to start
**	[1][i] : visited (1) or not (0)
**	[2][i] : preceding vertex of vertex i
*/

int			path_finding(t_clist ***path, t_vertex *vertex, t_clist **adj_list)
{
	int		**path_data;

	if (!(path_data = init_path_data_tab(vertex[0].x)))
		return (1);
	djikstra(path_data, vertex, adj_list);
	if (save_path(path, 1, path_data))
		return (1);
	return (0);
}
