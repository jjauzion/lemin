/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:45:12 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/08 15:11:56 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# define START 1
# define END 2
# define VERTEX_DEF_NB 100

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

#endif
