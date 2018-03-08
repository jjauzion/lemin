/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:25:20 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 10:11:24 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Realloc memory to "src":
**	A fresh memory space is allocated of size "len" + "size"
**	Byte from 0 to len + 1 (A CHANGER !!!!) from "src" are copied with ft_memcpy
**	to the new memory space allocated.
**	Original "src" pointer is freed.
**
**	Return :
**	A pointer to the new allocated memory space is returned.
*/

#include "libft.h"

void		*ft_realloc(void **src, size_t len, size_t size)
{
	void	*dst;

	if (!(dst = ft_memalloc(len + size)))
		return (NULL);
	dst = ft_memcpy(dst, *src, len);
	free(*src);
	*src = NULL;
	return (dst);
}
