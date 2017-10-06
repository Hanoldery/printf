/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:45:39 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/16 19:43:52 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		st_getlength(int n)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
		return (st_getlength(-n) + 1);
	if (n > 9)
		return (st_getlength(n / 10) + 1);
	return (1);
}

static char		*st_intmin(void)
{
	char	*i;

	i = ft_strnew(st_getlength(-2147483648) + 1);
	ft_strcpy(i, "-2147483648");
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		length;

	length = st_getlength(n);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		n = -n;
	}
	if (n == -2147483648)
		return (st_intmin());
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
