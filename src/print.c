/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:31:50 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/10 16:57:58 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_adj_list(t_clist **list, int size)
{
	int		i;
	t_clist	*ptr;

	if (!list)
		return ;
	i = -1;
	while (++i < size)
	{
		ft_printf("%3d: |", i);
		ptr = list[i];
		while (ptr)
		{
			ft_printf("%d", ptr->nb);
			if (ptr->next)
				ft_printf("-");
			ptr = ptr->next;
		}
		ft_printf("|\n");
	}
}

void		print_path_data(int **path_data, int size)
{
	int		i;

	ft_printf(" i : %11s | ? | pre |\n", "dist2node");
	i = -1;
	while (++i < size)
		ft_printf("%3d: %11d | %d | %3d |\n", i, path_data[0][i], path_data[1][i], path_data[2][i]);
}

void		print_path(int **path)
{
	int	i;
	int	j;

	i = -1;
	while (path[++i])
	{
		ft_printf("Path n%d: |", i);
		j = -1;
		while (path[i][++j] >= 0)
		{
			ft_printf("%d", path[i][j]);
			if (path[i][j] != 1)
				ft_printf("-");
		}
		ft_printf("|\n");
	}
}
