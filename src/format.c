/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:28:53 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/05 19:08:26 by pgerbaud         ###   ########.fr       */
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
			(*lstconv)->attr = 
				putstr_in_str_if_diff((*lstconv)->attr, "0", 0, 0);
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

char		*conv_fmt(t_conv **lstconv, char *fmt)
{
	char	*tmp;

	tmp = NULL;
	if (*fmt == 'd' || *fmt == 'D')
	{
		if ((tmp = ft_strchr((*lstconv)->attr, '0'))
			&& (ft_strchr((*lstconv)->attr, '.')))
			while (*tmp)
				if ((*tmp = *(tmp + 1)))
					tmp++;
	}
//	WTF is that ?!
	if ((tmp = ft_strchr((*lstconv)->attr, '0'))
			&& (ft_strchr((*lstconv)->attr, '-')))
			while (*tmp)
				if ((*tmp = *(tmp + 1)))
					tmp++;
	if (*fmt == 'i')
		(*lstconv)->conv = 'd';
	else if (*fmt == 'p')
	{
		(*lstconv)->conv = 'x';
		if (!ft_strchr((*lstconv)->attr, '#'))
			(*lstconv)->attr[ft_strlen((*lstconv)->attr)] = '#';
	}
	else
		(*lstconv)->conv = *fmt;
	if (ft_strchr("ouUxX", (*lstconv)->conv)
			&& (tmp = ft_strchr((*lstconv)->attr, '+')))
		while (*tmp)
			if ((*tmp = *(tmp + 1)))
				tmp++;
	/* Handle specifics */
	if (ft_strchr("DUO", (*lstconv)->conv))
	{
		(*lstconv)->conv = (*lstconv)->conv + 32;
		if (!(*(*lstconv)->modif == 'l'))
			*(*lstconv)->modif = 'l';
	}
	sort_attr(&(*lstconv)->attr);
	return (NULL);
}
