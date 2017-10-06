/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:05:03 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/16 19:44:14 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = -1;
	while (++index < n)
	{
		if (*((unsigned char *)s1 + index) != *((unsigned char *)s2 + index))
			return (*((unsigned char *)s1 + index) -
					*((unsigned char *)s2 + index));
	}
	return (0);
}
