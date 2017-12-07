/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:38:35 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/12/07 17:22:35 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		handle_invalid_conv(t_conv **conv, char **rslt, int *b, int *e)
{
	int		i;
	int		len;
	int		minus;

	i = 0;
	minus = (ft_strchr((*conv)->attr, '-')) ? *e - *b + 1 : 0;
	len = ft_strlen(*rslt);
	(*conv)->valid = 0;
	(*conv)->champs--;
	if ((*conv)->champs_changed)
	{
		while (*(*rslt + i) && *(*rslt + i) != '%')
			i++;
		while ((*conv)->champs > 0 && ft_strlen(*rslt) - len < (*conv)->champs)
			*rslt = (ft_strchr((*conv)->attr, '0')) ?
				ft_addinstr(*rslt, "0", 0, minus + i++) :
				ft_addinstr(*rslt, " ", 0, minus + i++);
	}
	if (!minus && (*conv)->champs_changed)
	{
		*e += (*conv)->champs;
		*b += (*conv)->champs - 1;
	}
	else
		*b -= 1;
}

int			handle_void(t_conv **conv, char **tmp, char **rslt, int i)
{
	if (!ft_strlen(*tmp))
		ft_strdelinside(rslt, i - 1, i + 1);
	else if (is_null(conv) && ft_strchr("oOxX", (*conv)->conv)
			&& (*conv)->prec_changed &&
			!(ft_strchr((*conv)->attr, '#') && ft_strchr("oO", (*conv)->conv)))
	{
		if (!(*conv)->champs_changed)
		{
			ft_strdelinside(rslt, i - 2, i);
			return (1);
		}
		i = ft_strfind(*tmp, '0');
		ft_strdelinside(tmp, i - 1, i + 1);
		*tmp = ft_addinstr(*tmp, " ", "0", i);
		return (0);
	}
	else
		return (0);
	return (1);
}

int			is_null(t_conv **conv)
{
	//printf("\t\t\tIS_NULL 0%d\n.data%p sdata%p udata%p conv%p\n",(*conv)->pos, (*conv)->data, (*conv)->sdata, &(*conv)->udata, *conv);
	if (!(*conv)->data || !(*conv)->sdata)
	{
		//printf("\t\t\tIS_NULL 0.0\n");
		return (1);
	}
	//printf("\t\t\tIS_NULL 1\n.%p %p\n", (*conv)->data, (*conv)->sdata);
	if (!*(*conv)->data && !*(*conv)->sdata && !(*conv)->udata
			&& (*conv)->conv != '%'
			&& !(ft_strchr("s", (*conv)->conv) && *(*conv)->modif == 'l'))
	{
		//printf("\t\t\tIS_NULL 1.1\n");
		return (1);
	}
	//printf("\t\t\tIS_NULL 2\n");
	return (0);
}

int			handle_null(t_conv **conv, char **tmp, int j)
{
	int		i;

	i = 0;
	//printf("\t\t HANDLE_NULL 0 tmp.%p\n", *tmp);
	if (is_null(conv))
	{
		//printf("\t\t HANDLE_NULL 1 tmp.%p\n", *tmp);
		if (ft_strchr("oOxX", (*conv)->conv) || ft_strchr((*conv)->attr, '#')
				|| ((*conv)->conv == 'd' && (!(*conv)->prec_changed
					|| (*conv)->precision != 0))
				|| ((*conv)->conv == 'u' && !(*conv)->prec_changed))
			return (0);
		//printf("\t\t HANDLE_NULL 2 tmp.%p\n", *tmp);
		if (ft_strchr("sS", (*conv)->conv) && (*conv)->prec_changed == 0)
		{
			*tmp = ft_strcpy(*tmp, "(null)");
			return (1);
		}
		//printf("\t\t HANDLE_NULL 3 tmp.%p\n", *tmp);
		if ((*conv)->conv == 'c')
			i = ((*conv)->champs_changed) ? i + (*conv)->champs + 1 : i + 1;
		(*conv)->pos = ((*conv)->champs_changed) ? j + (*conv)->champs - 1 : j;
		//printf("\t\t HANDLE_NULL 4 tmp.%p\n", *tmp);
		while (*(*tmp + i))
			*(*tmp + i++) = '\0';
		//printf("\t\t HANDLE_NULL 5 tmp.%p\n", *tmp);
		return (1);
	}
	//printf("\t\t HANDLE_NULL 0.1 tmp.%p\n", *tmp);
	return (0);
}
