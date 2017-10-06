/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:43:07 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/09 14:37:13 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*temp;

	index = -1;
	temp = (unsigned char *)s;
	while (++index < n)
		if (*(temp + index) == (unsigned char)c)
			return ((void *)temp + index);
	return (NULL);
}
