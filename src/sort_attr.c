/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:28:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/11/21 16:26:21 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		check_doublon(t_conv **conv, char **a)
{
	int		i;
	int		j;
	char	tmp;

	tmp = 0;
	i = 0;
	j = 0;
	while ((*a)[i])
	{
		tmp = (*a)[i];
		j = i + 1;
		while ((*a)[j])
			if (tmp == (*a)[j++])
			{
				ft_strdelinside(a, j - 2, j);
				i = 0;
			}
		i++;
	}
}

void		zero_front(t_conv **conv, char **a)
{
	char	tmp;
	int		i;

	tmp = 0;
	i = 0;
	if (ft_strchr(*a, '0'))
	{
		tmp = **a;
		i = ft_strfind(*a, '0');
		**a = '0';
		*(*a + i) = tmp;
	}
}

void		sort_attr(t_conv **conv, char **a)
{
	int		i;
	int		j;
	char	tmp;

	tmp = 0;
	i = 0;
	i = 0;
	check_doublon(conv, a);
	if (ft_strchr(*a, ' ') && ft_strchr(*a, '+'))
	{
		i = ft_strfind(*a, ' ');
		ft_strdelinside(a, i - 1, i + 1);
	}
	if (ft_strchr(*a, ' ') && ft_strchr("xXo", (*conv)->conv))
	{
		i = ft_strfind(*a, ' ');
		ft_strdelinside(a, i - 1, i + 1);
	}
	if (ft_strchr(*a, '0') && ft_strchr(*a, '-'))
		ft_strdelinside(a, ft_strfind(*a, '0') - 1, ft_strfind(*a, '0') + 1);
	if (ft_strchr(*a, '0')
			&& ((*conv)->prec_changed && (*conv)->precision != 0))
		ft_strdelinside(a, ft_strfind(*a, '0') - 1, ft_strfind(*a, '0') + 1);
}
