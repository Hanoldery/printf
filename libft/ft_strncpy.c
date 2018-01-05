/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:47:40 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/09 15:49:03 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		index;

	index = 0;
	while (*(src + index) != '\0' && index < len)
	{
		*(dst + index) = *(src + index);
		index++;
	}
	while (index < len)
	{
		*(dst + index) = '\0';
		index++;
	}
	return (dst);
}
