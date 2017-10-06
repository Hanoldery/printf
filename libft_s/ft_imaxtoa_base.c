/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:02:19 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/05 13:38:23 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int			count_final_number_size(intmax_t value, intmax_t base)
{
	int		i;

	i = 0;
	while (value != 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}

char		*ft_imaxtoa_base(intmax_t value, int base)
{
	char		*baser;
	int			i;
	intmax_t	tmp;
	char		*rslt;

	baser = ft_strdup("0123456789ABCDEF");
	i = 0;
	tmp = value;
	i = count_final_number_size(tmp, (intmax_t)base);
	if ((base < 2 || base > 16) || !(rslt = ft_strnew(i * 2)) || value == 0)
		return ("0");
	if (value < 0)
	{
		rslt[0] = '-';
		i++;
		if (base == 10 && value == -2147483648)
			return "-2147483648";
		tmp = -tmp;
	}
//	printf("-> 2.0 %ld\n", tmp);
	while (tmp != 0)
	{
		rslt[--i] = baser[tmp%base];
		tmp = tmp/(intmax_t)base;
	}
	return (rslt);
}
