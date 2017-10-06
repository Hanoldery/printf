/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:45:42 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/05 13:42:08 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uintmax_t		st_getlength(uintmax_t n)
{
	if (n > 9)
		return (st_getlength(n / 10) + 1);
	return (1);
}

char			*ft_uimaxtoa(uintmax_t n)
{
	char	*str;
	int		length;

	length = st_getlength(n);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		*str = '0';
	*(str + length--) = '\0';
	while (n > 0)
	{
		*(str + length--) = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
