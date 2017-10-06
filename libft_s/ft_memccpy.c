/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:11:52 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/09 14:36:58 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		*((unsigned char *)dst + index) = *((unsigned char *)src + index);
		if (*((unsigned char *)src + index) == (unsigned char)c)
			return ((unsigned char *)dst + index + 1);
		index++;
	}
	return (NULL);
}
