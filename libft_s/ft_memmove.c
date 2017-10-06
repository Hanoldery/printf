/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:49:56 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/09 14:37:04 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;
	size_t	max;
	size_t	way;

	max = len;
	way = 1;
	index = 0;
	if (src != dst)
	{
		if (dst > src)
		{
			max = -1;
			way = -1;
			index = len - 1;
		}
		while (index != max)
		{
			*(((unsigned char*)dst) + index) = *(((unsigned char*)src) + index);
			index += way;
		}
	}
	return (dst);
}
