/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:17:03 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/09 19:14:33 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	**path_data:
**	[0] : vertex id
**	[1] : distance from start
**	[2] : visited or not
**	[3] : preceding verttex
*/

int			path_finding(t_paths *path, t_vertex *vertex, t_clist **adj_list)
{
	int		**path_data;

	path_data = init_path_data_tab(vertex[0].x);
	if (!path_data)
		return (0);
	return (0);
	(void)path;
	(void)adj_list;
}
