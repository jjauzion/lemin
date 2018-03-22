/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:24:01 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/22 12:56:25 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		read_cmd(char *line, int option)
{
	if (ft_strequ(line, "##start"))
	{
		print_maze("##start");
		option = OPT_START;
	}
	else if (ft_strequ(line, "##end"))
	{
		print_maze("##end");
		option = OPT_END;
	}
	return (option);
}

static int		get_nb_of_ants(char *word, int *nb_of_ant)
{
	intmax_t tmp;

	if (*nb_of_ant >= 0)
		return (-1);
	tmp = ft_atoim(word);
	if (tmp < 0 || tmp > INT_MAX)
		return (-1);
	*nb_of_ant = (int)tmp;
	return (0);
}

static int		parse_line(char *line, t_vertex **vertex, t_clist ***adj_list,
		int option)
{
	char	**word;
	int		i;
	int		ret;

	if (!(word = ft_strsplit(line, ' ')))
		return (-1);
	i = 0;
	while (word[i])
		i++;
	if (i == 3)
		ret = add_vertex(word, vertex, option);
	else if (i == 1)
	{
		if (ft_isnumber(word[0]))
			ret = get_nb_of_ants(word[0], &(*vertex)[0].y);
		else
			ret = add_link(line, *vertex, adj_list);
	}
	else
		ret = 1;
	free_word(&word);
	return (ret);
}

int				parse(t_vertex **vertex, t_clist ***adj_list)
{
	int		ret;
	char	*line;
	int		option;

	if (!(*vertex = init_vertex(VERTEX_DEF_NB)))
		return (1);
	option = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if ((line[0] != '#' || line[1] == '#') && line[0] != '\0')
		{
			if (line[0] == '#' && line[1] == '#' && option != OPT_LINK)
				option = read_cmd(line, option);
			else
			{
				option = parse_line(line, vertex, adj_list, option);
			}
		}
		print_maze(line);
		ft_strdel(&line);
		if (option < 0)
			return (0);
	}
	ft_strdel(&line);
	return (0);
}
