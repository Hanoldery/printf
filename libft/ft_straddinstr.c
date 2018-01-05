/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddinstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:29:48 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/05 13:51:42 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*openstr(char *dst, char *src, int index)
{
	int		i;
	int		j;
	int		max;

	max = ft_strlen(dst);
	j = ft_strlen(dst) - index + 1;
	i = -1;
	while (++i < (int)ft_strlen(src))
	{
		while (--j >= 0)
			dst[index + i + j + 1] = dst[index + i + j];
		j = max - index + 1;
	}
	return (dst);
}

char		*ft_addinstr(char *dst, char *src, char *eq, int index)
{
	int		plus;

	plus = 0;
	if (eq && ft_strchr(eq, *(dst + index)))
	{
		*(dst + index) = *src;
		src++;
		plus++;
	}
	if (dst && *dst)
	{
		dst = openstr(dst, src, index);
		ft_memcpy(dst + index + plus, src, ft_strlen(src));
	}
	else
		dst = ft_strcat(dst, src);
	return (dst);
}
