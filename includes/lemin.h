/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:45:12 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/21 10:20:10 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# define OPT_START 1
# define OPT_END 2
# define OPT_LINK 3
# define PATH_DEF_NB 500
# define VERTEX_DEF_NB 5000

typedef struct		s_vertex
{
	char			*name;
	int				x;
	int				y;
	int				ant;
}					t_vertex;

typedef struct		s_clist
{
	int				nb;
	struct s_clist	*next;
}					t_clist;

typedef struct		s_solution
{
	int				**path;
	int				nb_of_path;
}					t_sol;

t_vertex			*init_vertex(int size);
t_clist				**init_adj_list(int size);
int					**init_path_data_tab(int size);
t_sol				*init_solution(int size);
void				free_word(char ***word);
void				free_vertex(t_vertex **vertex);
void				free_adj_list(t_clist ***adj_list, int size);
void				free_int_matrix(int ***matrix, int size);
void				free_solution(t_sol **sol);
int					parse(t_vertex **vertex, t_clist ***adj_list);
int					add_vertex(char **word, t_vertex **vertex, int option);
int					add_link(char *line, t_vertex *vertex, t_clist ***adj_list);
int					check_name(t_vertex *vertex, char *name);
t_clist				*new_elm(int data);
int					add2list(t_clist **list, int data);
void				free_list(t_clist **list);
void				remove_elm(t_clist **list, int data);
int					get_nb_elm(t_clist *list);
t_clist				*copy_list(t_clist *list);
int					path_finding(int **path, t_vertex *vertex,
		t_clist **adj_list);
int					djikstra(int **path_data, t_vertex *v, t_clist **adj_list);
void				run_ants_run(int **path, int nb_of_path, t_vertex *vertex);
void				print_adj_list(t_clist **list, int size);
void				print_path_data(int **path_data, int size);
void				print_path(int **path, t_vertex *vertex);
void				print_maze(char *str);
int					remove_start_link(int link_id, t_clist **list);
t_clist				**copy_adj_list(t_clist **list, int size);
int					find_best_solution(t_sol *sol, int nb_of_ant);
int					copy_path(int **dest, int **src, int nb_of_path);
void				reinit_path_data(int **path_data, int size);
void				remove_path_from_graph(int *path, t_clist **adj_list,
		int nb_vertex);
int					add_path(int **path, int nb_of_path, int **path_data);
int					sort_path(int **path, int nb_of_path, int path_length);

#endif
