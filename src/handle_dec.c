/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:45:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/09/19 15:58:59 by pgerbaud         ###   ########.fr       */
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
//	printf("CONV xX\n");
	str = ft_itoa_base((*conv)->data[0], 16);
	if ((*conv)->conv == 'x')
	{
		while (str[i])
		{
			if (str[i] > 64 || str[i] < 71)
				str[i] = str[i] + 27;
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

//	printf("CONV D\n");
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
	str = ft_itoa_base((*conv)->data[0], 8);
	i = id_of_char(fmt, '%', '%');
	str = putstr_in_str_if_diff(fmt, str, '%', i);
	str = fill_prec(str, (*conv)->precision);
	return (str);
}
