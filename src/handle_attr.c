/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_attr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:42:05 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/11/21 12:59:52 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*handle_champs(t_conv **conv, char *fmt)
{
	int		i;
	char	*c;
	int		index;

	index = 0;
	c = ft_strnew(2);
	i = ft_strlen(fmt);
	if (ft_strchr((*conv)->attr, '0'))
		*c = '0';
	else
		*c = ' ';
	if ((*(*conv)->data < 0 && ft_strchr((*conv)->attr, '0'))
			|| (ft_strchr((*conv)->attr, '+') && ft_strchr((*conv)->attr, '0'))
			|| ft_strchr((*conv)->attr, ' '))
		index = 1;
	if (ft_strchr("xXp", (*conv)->conv) && ft_strchr((*conv)->attr, '#')
			&& ft_strchr((*conv)->attr, '0'))
		index = 2;
	while (i++ < (*conv)->champs)
		fmt = (ft_strchr((*conv)->attr, '-')) ?
			ft_addinstr(fmt, c, 0, ft_strlen(fmt)) :
			ft_addinstr(fmt, c, 0, index);
	return (fmt);
}

char		*handle_space_plus(t_conv **conv, char *fmt)
{
	int		i;
	char	*rslt;

	i = 0;
	rslt = NULL;
	if ((!ft_strchr("dDxXoOi", (*conv)->conv) ||
				ft_strchr((*conv)->modif, 'l')) || *((*conv)->data) < 0)
		return (fmt);
	if (i > 0)
		i--;
	if (ft_strchr((*conv)->attr, '+') && (*conv)->data)
		rslt = ft_addinstr(fmt, "+", 0, i);
	else if (ft_strchr((*conv)->attr, ' ') && (*conv)->conv != '%')
		rslt = ft_addinstr(fmt, " ", 0, i);
	else
		return (fmt);
	return (rslt);
}

char		*handle_hash(t_conv **conv, char *fmt)
{
	int	i;

	i = 0;
	while (ft_strchr(" %+", *(fmt + i)))
		i++;
	if ((*conv)->conv == 'o')
	{
		if (*(fmt + i) != '0')
			fmt = ft_addinstr(fmt, "0", " ", i);
		return (fmt);
	}
	if ((*conv)->conv == 'p' && (*conv)->udata == 0)
		fmt = ft_addinstr(fmt, "0x", " ", i);
	if (ft_strchr("xXp", (*conv)->conv) && (*conv)->udata != 0)
		fmt = (ft_strchr("xp", (*conv)->conv)) ?
			ft_addinstr(fmt, "0x", " 0", i)
			: ft_addinstr(fmt, "0X", " 0", i);
	if ((*conv)->conv == 'p' && (*conv)->udata == 0 && (*conv)->prec_changed
			&& (*conv)->precision == 0)
		fmt[2] = '\0';
	return (fmt);
}
