/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:28:53 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/11/21 12:50:46 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*field_fmt(t_conv **lstconv, char *fmt)
{
	int		i;
	int		field_next;

	i = 0;
	field_next = 0;
	if (*fmt == '*')
	{
		field_next = 1;
		fmt++;
	}
	while (ft_strchr("0123456789", fmt[i]))
		i++;
	if (field_next && *(fmt + i) == '$')
		(*lstconv)->champs = -1 * ft_atoi(ft_strsub(fmt, 0, i));
	else if (!field_next && i > 0)
		(*lstconv)->champs = ft_atoi(ft_strsub(fmt, 0, i));
	if (field_next && (*lstconv)->champs == 0)
		(*lstconv)->champs = -1;
	else
		(*lstconv)->champs_changed = 1;
	if (*(fmt + i) == '$')
		fmt++;
	return (fmt + i);
}

char		*prec_fmt(t_conv **lstconv, char *fmt)
{
	int i;
	int field_next;

	field_next = 1;
	i = 0;
	fmt++;
	if (*fmt == '*')
		fmt = fmt + 1;
	else
		field_next = 0;
	while (ft_strchr("0123456789", fmt[i]))
		i++;
	if (field_next)
		(*lstconv)->precision = -1 * ft_atoi(ft_strsub(fmt, 0, i));
	else
		(*lstconv)->precision = ft_atoi(ft_strsub(fmt, 0, i));
	if (fmt[i] == '$')
		fmt++;
	if (field_next && (*lstconv)->precision == 0)
		(*lstconv)->precision = -1;
	else
		(*lstconv)->prec_changed = 1;
	return (fmt + i);
}

char		*attr_fmt(t_conv **lstconv, char *fmt)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (ft_strchr("#0-+ ", *fmt))
	{
		if (*fmt == '0' && ft_strchr((*lstconv)->attr, '+'))
			(*lstconv)->attr = ft_addinstr((*lstconv)->attr, "0", 0, 0);
		else
			(*lstconv)->attr[i++] = *fmt;
		if (*fmt == '-')
			if ((tmp = ft_strchr((*lstconv)->attr, '0')))
				while (*tmp)
					if ((*tmp = *(tmp + 1)))
						tmp++;
		fmt++;
	}
	return (fmt);
}

char		*length_fmt(t_conv **lstconv, char *fmt)
{
	if (*fmt == 'h' && *(fmt + 1) == 'h')
	{
		(*lstconv)->modif = "hh";
		fmt++;
	}
	else if (*fmt == 'l' && *(fmt + 1) == 'l')
	{
		(*lstconv)->modif = "ll";
		fmt++;
	}
	else
		*(*lstconv)->modif = *fmt;
	return (fmt + 1);
}

char		*conv_fmt(t_conv **lst, char *fmt)
{
	if (*fmt == 'd' || *fmt == 'D')
		if (ft_strchr((*lst)->attr, '0') && (ft_strchr((*lst)->attr, '.')))
			ft_strdelinside(&(*lst)->attr, ft_strfind((*lst)->attr, '+') - 1,
				ft_strfind((*lst)->attr, '+') + 1);
	if (*fmt == 'i')
		(*lst)->conv = 'd';
	else if (*fmt == 'p')
	{
		(*lst)->conv = *fmt;
		if (!ft_strchr((*lst)->attr, '#'))
			(*lst)->attr[ft_strlen((*lst)->attr)] = '#';
	}
	else
		(*lst)->conv = *fmt;
	if (ft_strchr("ouUxX", (*lst)->conv) && ft_strchr((*lst)->attr, '+'))
		ft_strdelinside(&(*lst)->attr, ft_strfind((*lst)->attr, '+') - 1,
				ft_strfind((*lst)->attr, '+') + 1);
	if (ft_strchr("DUOSC", (*lst)->conv))
	{
		(*lst)->conv = (*lst)->conv + 32;
		(*lst)->modif = ft_addinstr((*lst)->modif, "l", 0, 0);
	}
	sort_attr(lst, &(*lst)->attr);
	return (NULL);
}
