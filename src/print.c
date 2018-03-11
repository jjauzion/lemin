/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:31:50 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/11 17:35:36 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	*join(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s2)
		return (NULL);
	if (!s1)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len1 + len2 + 2))))
		return (NULL);
	i = 0;
	while (i < (len1 + len2))
	{
		if (i < len1)
			ret[i] = s1[i];
		else
			ret[i] = s2[i - len1];
		i++;
	}
	ret[i] = '\n';
	ret[i + 1] = '\0';
	return (ret);
}

void		print_maze(char *str)
{
	static char		*buff;
	char			*tmp;

	if (!str)
	{
		ft_printf("%s\n", buff);
		free(buff);
		return ;
	}
	tmp = buff;
	buff = join(buff, str);
	free(tmp);
}

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

void		print_path(int **path, t_vertex *vertex)
{
	int	i;
	int	j;

	i = -1;
	while (path[++i])
	{
		ft_printf("Path n%d: |", i);
		j = 0;
		while (++j <= path[i][0] + 1)
		{
			ft_printf("%s", vertex[path[i][j] + 1].name);
			if (path[i][j] != 1)
				ft_printf("-");
		}
		ft_printf("|\n");
	}
}
