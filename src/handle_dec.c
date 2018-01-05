/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:45:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/05 14:27:38 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*fill_prec(char *fmt, int prec, int sign)
{
	while ((int)ft_strlen(fmt) < prec + sign)
		fmt = ft_addinstr(fmt, "0", 0, sign);
	return (fmt);
}

char		*handle_x(t_conv **conv, char *fmt)
{
	int		i;
	char	*str;

	i = -1;
	str = NULL;
	if ((*conv)->udata <= (uintmax_t)(-4294967295))
		str = ft_uimaxtoa_base(UINTMAX_MAX + (*conv)->udata + 1, 16);
	else if (!((*conv)->udata > 0))
		str = ft_uimaxtoa_base(4294967295 + (*conv)->udata + 1, 16);
	else
		str = ft_uimaxtoa_base((*conv)->udata, 16);
	if (ft_strchr("xp", (*conv)->conv))
		while (str[++i])
			if (str[i] > 64 && str[i] < 71)
				str[i] = str[i] + 32;
	i = id_of_char_ifnextnot(fmt, '%', '%');
	fmt = ft_addinstr(fmt, str, "% ", i);
	if ((*conv)->udata != 0 && (*conv)->precision - 2 > 0
			&& ft_strchr((*conv)->attr, '#'))
		fmt = fill_prec(fmt, (*conv)->precision + 1, 0);
	else
		fmt = fill_prec(fmt, (*conv)->precision, 0);
	ft_strdel(&str);
	return (fmt);
}

char		*handle_di(t_conv **conv, char *fmt)
{
	int		i;
	char	*str;

	str = ft_imaxtoa((*conv)->data[0]);
	i = id_of_char_ifnextnot(fmt, '%', '%');
	fmt = ft_addinstr(fmt, str, "%", i);
	fmt = fill_prec(fmt, (*conv)->precision, (*conv)->data[0] < 0);
	ft_strdel(&str);
	return (fmt);
}

char		*handle_ou(t_conv **conv, char *fmt)
{
	int		i;
	char	*str;

	i = 0;
	if ((*conv)->conv == 'o')
		str = ft_uimaxtoa_base((*conv)->udata, 8);
	if ((*conv)->conv == 'u')
		str = ft_uimaxtoa((*conv)->udata);
	i = id_of_char_ifnextnot(fmt, '%', '%');
	fmt = ft_addinstr(fmt, str, "%", i);
	fmt = fill_prec(fmt, (*conv)->precision, 0);
	ft_strdel(&str);
	return (fmt);
}
