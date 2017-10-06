/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:13:43 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/18 12:10:01 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = (void *)malloc(sizeof(mem) * size);
	size++;
	if (mem)
	{
		while (--size > 0)
			*((char *)mem + size) = (unsigned char)0;
		*(char *)mem = (unsigned char)0;
	}
	return (mem);
}
