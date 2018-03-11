/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants_run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:25:46 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/11 16:04:59 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	move_ants(int **path, int nb_of_path, t_vertex *vertex)
{
	int	i;
	int	j;
	int	ant;
	int	node;

	i = -1;
	while (++i < nb_of_path)
	{
		j = path[i][0];
		while (j > 1)
		{
			node = path[i][j];
			if ((ant = vertex[node + 1].ant) > 0)
			{
				vertex[node + 1].ant = 0;
				node = path[i][j + 1];
				vertex[node + 1].ant = (node + 1 == 2) ? 1 + vertex[node + 1].ant : ant;
				ft_printf("L%d-%s ", ant, vertex[node + 1].name);
			}
			j--;
		}	
	}
}

static void	get_ants_outof_start(int **path, int nb_of_path, t_vertex *vertex)
{
	int	i;
	int	ant_id;

	i = -1;
	while (vertex[1].ant > 0 && ++i < nb_of_path)
	{
		ant_id = vertex[0].y - vertex[1].ant + 1;
		if (vertex[1].ant > (path[i][0] - path[0][0]))
		{
			vertex[path[i][2] + 1].ant = ant_id;
			ft_printf("L%d-%s ", ant_id, vertex[path[i][2] + 1].name);
			vertex[1].ant--;
		}
	}
}

void		run_ants_run(int **path, int nb_of_path, t_vertex *vertex)
{
//	ft_printf("\n");
	vertex[1].ant = vertex[0].y;
	while (vertex[2].ant < vertex[0].y)
	{
		move_ants(path, nb_of_path, vertex);
		get_ants_outof_start(path, nb_of_path, vertex);
		ft_printf("\n");
	}
}
