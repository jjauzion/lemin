/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:55:00 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/20 13:28:13 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	rate_solution(t_sol *sol, int index, int nb_of_ant)
{
	int	remaining_path;
	int	i;
	int	shortest_path;
	int	ants;

	i = sol[index].nb_of_path;
	remaining_path = sol[index].nb_of_path;
	shortest_path = sol[index].path[0][0];
	while (--i > 0)
	{
		ants = (nb_of_ant - (sol[index].path[i][0] - shortest_path)) /
			remaining_path;
		nb_of_ant = nb_of_ant - ants;
		remaining_path--;
	}
	return (shortest_path * ((nb_of_ant - 1) / shortest_path + 1) +
			(nb_of_ant - 1) % shortest_path);
}

int			find_best_solution(t_sol *sol, int nb_of_ant)
{
	int		i;
	int		tmp;
	int		nb_of_turn;
	int		ret;

	ret = -1;
	nb_of_turn = INT_MAX;
	i = -1;
	while (sol[++i].nb_of_path > 0)
	{
		tmp = rate_solution(sol, i, nb_of_ant);
		if (tmp <= nb_of_turn)
		{
			nb_of_turn = tmp;
			ret = i;
		}
	}
	return (ret);
}
