/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:02:19 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/05 13:52:14 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void		handle_neg(char **rslt, int *i, intmax_t *tmp, intmax_t value)
{
	if (value < 0)
	{
		(*rslt)[0] = '-';
		(*i)++;
		*tmp = -(*tmp);
	}
}

char		*ft_imaxtoa_base(intmax_t value, int base)
{
	char		*baser;
	int			i;
	intmax_t	tmp;
	char		*rslt;

	baser = NULL;
	tmp = 0;
	i = count_final_number_size(tmp, (intmax_t)base);
	tmp = value;
	rslt = NULL;
	if ((base < 2 || base > 16) || !(rslt = ft_strnew(i * 2)) || value == 0)
		return (ft_strdup("0"));
	if (base == 10 && value == -2147483648)
		return (ft_strdup("-2147483648"));
	rslt = ft_strnew(i);
	baser = ft_strdup("0123456789ABCDEF");
	handle_neg(&rslt, &i, &tmp, value);
	while (tmp != 0)
	{
		rslt[--i] = baser[tmp % base];
		tmp = tmp / (intmax_t)base;
	}
	ft_strdel(&baser);
	return (rslt);
}
