/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:45:12 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/10 13:10:14 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# define START 1
# define END 2
# define LINK_DEF 3
# define VERTEX_DEF_NB 1000

typedef struct 				s_vertex
{
	char			*name;
	int				x;
	int				y;
}							t_vertex;

typedef struct				s_clist
{
	int				nb;
	struct s_clist	*next;	
}							t_clist;

t_vertex			*init_vertex(int size);
t_clist				**init_adj_list(int size);
int					**init_path_data_tab(int size);
void				free_word(char ***word);
void				free_vertex(t_vertex **vertex);
void				free_adj_list(t_clist ***adj_list, int size);
int					parse(t_vertex **vertex, t_clist ***adj_list);
int					add_vertex(char **word, t_vertex **vertex, int option);
int					add_link(char *line, t_vertex *vertex, t_clist ***adj_list);
int					check_name(t_vertex *vertex);
t_clist				*new_elm(int data);
int					add2list(t_clist **list, int data);
int					path_finding(t_clist ***path, t_vertex *vertex, t_clist **adj_list);
void				djikstra(int **path_data, t_vertex *v, t_clist **adj_list);
void				print_adj_list(t_clist **list, int size);
void				print_path_data(int **path_data, int size);

#endif
