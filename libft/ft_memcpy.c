/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:42:21 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/12/08 17:45:49 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int		index;

	index = 0;
	while (index < (int)n)
	{
		*(char *)(dst + index) = *(char *)(src + index);
		index++;
	}
	return (dst);
}
