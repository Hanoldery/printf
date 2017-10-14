/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_attr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:42:05 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/05 17:46:10 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*handle_champs(t_conv **conv, char *fmt)
{
	int i;

	i = ft_strlen(fmt);
	while (i++ < (*conv)->champs)
	{
		if (ft_strchr((*conv)->attr, '-'))
			fmt = putstr_in_str_if_diff(fmt, " ", 0, ft_strlen(fmt));
		else
			fmt = putstr_in_str_if_diff(fmt, " ", 0, 0);
	}
	return (fmt);
}

char		*handle_zero(t_conv **conv, char *fmt)
{
	int		i;
	int		length;
	int		where;

	i = 0;
	where = 0;
	length = ft_strlen(fmt);
	if (ft_strchr("xX", (*conv)->conv) && ft_strchr((*conv)->attr, '#'))
		where = 2;
	while (i++ < ((*conv)->champs - length))
		fmt = putstr_in_str_if_diff(fmt, "0", 0, where);
/*	if (!ft_strchr((*conv)->attr, ' '))
		while (*(fmt + i) == ' ')
			*(fmt + i++) = '0';
	else
		while (*(fmt + i + 1) == ' ')
			*(fmt + i++ + 1) = '0';*/
	return (fmt);
}

char		*handle_minus(t_conv **conv, char *fmt)
{
	int		i;
	char	*rslt;
	char	*tmp;

	tmp = NULL;
	rslt = ft_strnew(ft_strlen(fmt));
	i = 0;
//	while (*(fmt + i) != '%' && *(fmt + i) != '0' && *(fmt + i) != '+')
	while (*(fmt + i) == ' ')
		i++;
	tmp = ft_strnew(i);
	if (ft_strchr((*conv)->attr, ' ') && *fmt == ' ')
		tmp = ft_strncat(tmp, fmt, --i);
	else
		tmp = ft_strncat(tmp, fmt, i);
	rslt = ft_strcat(rslt, fmt + i);
	rslt = ft_strcat(rslt, tmp);
	//TODO free(fmt);
	return (rslt);
}

char		*handle_space_plus(t_conv **conv, char *fmt)
{
	int		i;
	char	*rslt;

	i = 0;
	rslt = NULL;
//	if(!(*((*conv)->data) && *((*conv)->data) > 0))
//		return (fmt);
	while (*(fmt + i) == ' ')
		i++;
	//printf("\t\tSpace and plus %d _%s_\n", i, rslt);
	if (i > 0)
		i--;
	if (ft_strchr((*conv)->attr, '+'))
		rslt = putstr_in_str_if_diff(fmt, "+", ' ', i);
	else
		rslt = putstr_in_str_if_diff(fmt, " ", ' ', i);
	//printf("\t\tSpace and plus %d _%s_\n", i, rslt);
	return (rslt);
}

char		*handle_hash(t_conv **conv, char *fmt)
{
	int	i;

	i = 0;
	while (ft_strchr("0%+", *(fmt + i)))
		i++;
	if ((*conv)->conv == 'o')
		return ((*(fmt + i)) ? fmt: putstr_in_str_if_diff(fmt, "0", ' ', i));
	if (((*conv)->conv == 'x' || (*conv)->conv == 'X') && *((*conv)->data) != 0)
		fmt = ((*conv)->conv == 'x') ?
			putstr_in_str_if_diff(fmt, "0x", ' ', i)
			: putstr_in_str_if_diff(fmt, "0X", ' ', i);
	return (fmt);
}
