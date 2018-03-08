/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:24:01 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/08 19:43:02 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		read_cmd(char *line, int option)
{
	if (ft_strequ(line, "##start"))
		option = START;
	else if (ft_strequ(line, "##end"))
		option = END;
	return (option);
}

static int		add_vertex(char **word, t_vertex **vertex, int option)
{
	static int	max_nb_of_vertex = VERTEX_DEF_NB;
	static int	index = 0;
	int			i;
	intmax_t	x;
	intmax_t	y;
	
	if (index + 3 > max_nb_of_vertex)
	{
		if (!(*vertex = (t_vertex*)ft_realloc((void*)vertex, sizeof(t_vertex) *
						(max_nb_of_vertex + 1), sizeof(t_vertex) *
						VERTEX_DEF_NB)))
			return (-1);
		max_nb_of_vertex += VERTEX_DEF_NB;
	}
	i = 0;
	while(word[i])
		i++;
	if (i != 3 || !ft_isnumber(word[1]) || !ft_isnumber(word[2]))
		return (-1);
	x = ft_atoim(word[1]);
	y = ft_atoim(word[2]);
	if (x > INT_MAX || x < INT_MIN || y > INT_MAX || y < INT_MIN)
		return (-1);
	if (option == START)
		i = 1;
	else if (option == END)
		i = 2;
	else
	{
		i = index + 3;
		index++;
	}
	if ((*vertex)[i].name != NULL)
		return (-1);
	(*vertex)[i].name = ft_strdup(word[0]);
	(*vertex)[i].x = (int)x;
	(*vertex)[i].y = (int)y;
	(*vertex)[0].x++;
	return (0);
}

static int		parse_line(char *line, t_vertex **vertex, t_clist **adj_list,
		int option)
{
	char	**word;
	int		i;
	int		ret;

	if (!(word = ft_strsplit(line, ' ')))
		return (-1);
	i = -1;
	while (word[++i])
	{
	}
	if (i == 3)
	{
		ret = add_vertex(word, vertex, option);
		i = -1;
		while (word[++i])
			free(word[i]);
		free(word);
	}
	else if (i == 1)
//		ret = add_link();
		ret = 0;
	else
		ret = 1;
(void)adj_list;
	return (ret);
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
		if ((line[0] != '#' || line[1] == '#') && line[0] != '\0')
		{
			if (line[0] == '#' && line[1] == '#')
				option = read_cmd(line, option);
			else
				option = parse_line(line, vertex, adj_list, option);
		}
		ft_strdel(&line);
		if (option < 0)
			return (1);
	}
	if ((*vertex)[1].name == NULL || (*vertex)[2].name == NULL)
		return (1);
	return (0);
}
