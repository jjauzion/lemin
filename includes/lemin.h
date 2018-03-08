/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:45:12 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/08 19:44:35 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# define START 1
# define END 2
# define VERTEX_DEF_NB 1000

typedef struct 				s_vertex
{
	char					*name;
	int						x;
	int						y;
}							t_vertex;

typedef struct				s_connex_list
{
	int						nb;
	struct s_connex_list	*next;	
}							t_clist;

t_vertex					*init_vertex(int size);
int							parse(t_vertex **vertex, t_clist **adj_list);
int							check_name(t_vertex *vertex);

#endif
