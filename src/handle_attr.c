/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_attr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:42:05 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/12/07 18:20:35 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*fill_champs(t_conv **conv, char *fmt, char *c, int index)
{
	int		hex;

	/* CHANGER CETTE FACON DE FAIRE POUR UN TRUC PLUS RAPIDE*/
	while ((*conv)->champs > 0 && ft_strlen(fmt) < (*conv)->champs)
	{
		//printf("FILL_CHAMPS BCL _%c_ %d %d\n", *c, (*conv)->champs, ft_strlen(fmt));
		fmt = (ft_strchr((*conv)->attr, '-')) ?
			ft_addinstr(fmt, c, 0, ft_strlen(fmt)) :
			ft_addinstr(fmt, c, 0, index);
	}
	return (fmt);
}

char		*handle_champs(t_conv **conv, char *fmt)
{
	char	*rslt;
	char	c;
	int		index;

	rslt = NULL;
	index = 0;
	c = ' ';
	if (ft_strchr((*conv)->attr, '0'))
		c = '0';
	if ((*(*conv)->data < 0 && ft_strchr((*conv)->attr, '0'))
			|| (ft_strchr((*conv)->attr, '+') && ft_strchr((*conv)->attr, '0'))
			|| ft_strchr((*conv)->attr, ' '))
		index = 1;
	if (ft_strchr("xXp", (*conv)->conv) && ft_strchr((*conv)->attr, '#')
			&& ft_strchr((*conv)->attr, '0'))
		index = 2;
	rslt = fill_champs(conv, fmt, &c, index);
	return (rslt);
}

char		*handle_space_plus(t_conv **conv, char *fmt)
{
	int		i;
	char	*rslt;

	i = 0;
	rslt = fmt;
	if ((!ft_strchr("dDxXoOi", (*conv)->conv) ||
				ft_strchr((*conv)->modif, 'l')) || *((*conv)->data) < 0)
		return (rslt);
	if (i > 0)
		i--;
	if (ft_strchr((*conv)->attr, '+') && (*conv)->data)
		rslt = ft_addinstr(rslt, "+", 0, i);
	else if (ft_strchr((*conv)->attr, ' ') && (*conv)->conv != '%')
		rslt = ft_addinstr(rslt, " ", 0, i);
	else
	{
		free(fmt);
		return (rslt);
	}
	free(fmt);
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
