/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:02:19 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/05 14:53:27 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int			ucount_final_number_size(uintmax_t value, uintmax_t base)
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

char		*ft_uimaxtoa_base(uintmax_t value, int base)
{
	char		*baser;
	int			i;
	uintmax_t	tmp;
	char		*rslt;

	baser = ft_strdup("0123456789ABCDEF");
	tmp = value;
	i = ucount_final_number_size(tmp, (uintmax_t)base);
	if ((base < 2 || base > 16) || !(rslt = ft_strnew(i * 2)) || value == 0)
		return ("0");
	while (tmp != 0)
	{
		rslt[--i] = baser[tmp%base];
		tmp = tmp/(long)base;
	}
	return (rslt);
}
