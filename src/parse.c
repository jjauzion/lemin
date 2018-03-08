/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:24:01 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/08 15:18:50 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_vertex	*init_vertex(int size)
{
	t_vertex	*vertex;

	if (!(vertex = (t_vertex*)malloc(sizeof(t_vertex) * (size + 1))))
		return (NULL);
}

static int		read_cmd(char *line, int option)
{
	if (ft_strequ(line, "##start"))
		option = START;
	else if (ft_strequ(line, "##end"))
		option = END;
	return (option);
}

int				parse(t_vertex **vertex, t_clist **adj_list)
{
	int		ret;
	char	*line;
	int		option;

	if (!(*vertex = init_vertex(VERTEX_DEF_NB)))
		return (1);
	option = 0;
	while((ret = get_next_line(0, &line)) > 0)
	{
		if (line[0] != "#" || line[1] == "#")
		{
			if (line[0] == "#" && line[1] == "#")
				option = read_cmd(&linei, option);
			else
				option = parse_line(line, vertex, adj_list, option);
		}
		ft_strdel(&line);
	}
}
