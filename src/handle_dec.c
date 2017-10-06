/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:45:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/05 19:10:27 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*fill_prec(char *fmt, int prec)
{
	while (ft_strlen(fmt) < prec)
		fmt = putstr_in_str_if_diff(fmt, "0", 0, 0);
	return (fmt);
}

char		*handle_xX(t_conv **conv, char *fmt)
{
	int		i;
	char	*str;

	i = 0;
	if ((*conv)->data[0] <= -4294967295)
		str = ft_uimaxtoa_base((uintmax_t)18446744073709551615 + (*conv)->data[0]  + 1, 16);
	else if ((*conv)->data[0] < 0)
		str = ft_uimaxtoa_base(4294967295 + (*conv)->data[0] + 1, 16);
	else 
		str = ft_imaxtoa_base((*conv)->data[0], 16);
	if ((*conv)->conv == 'x')
	{
		while (str[i])
		{
			if (str[i] > 64 && str[i] < 71)
				str[i] = str[i] + 32;
			i++;
		}
	}
	i = id_of_char(fmt, '%', '%');
	str = putstr_in_str_if_diff(fmt, str, '%', i);
	str = fill_prec(str, (*conv)->precision);
	return (str);
}

char		*handle_diu(t_conv **conv, char *fmt)
{
	int		i;
	char	*str;

	str = ft_imaxtoa((*conv)->data[0]);
	i = id_of_char(fmt, '%', '%');
	str = putstr_in_str_if_diff(fmt, str, '%', i);
	str = fill_prec(str, (*conv)->precision);
	return (str);
}

char		*handle_o(t_conv **conv, char *fmt)
{
	int		i;
	char	*str;

	i = 0;
//	printf("CONV o\n");
	str = ft_imaxtoa_base((*conv)->data[0], 8);
	i = id_of_char(fmt, '%', '%');
	str = putstr_in_str_if_diff(fmt, str, '%', i);
	str = fill_prec(str, (*conv)->precision);
	return (str);
}
