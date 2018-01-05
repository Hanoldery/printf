/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:20:01 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/05 14:23:11 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*delete_conv_inside(char *rslt, t_conv **lst)
{
	int		begin;
	int		end;

	begin = 0;
	end = 0;
	while (*(rslt + begin))
	{
		while (*(rslt + begin) != '%')
			if (!*(rslt + begin++))
				return (rslt);
		end = begin + 1;
		while (!ft_strchr("diouxXeEfFgGaAcCsSpn%", *(rslt + end))
				&& ft_strchr(" -+0123456789#*$.hjzlL", *(rslt + end)))
			end++;
		if (ft_strchr(" -+0123456789#*$.hjzlLdDioOuUxXeEfFgGaAcCsSpn%",
					*(rslt + end)) && *(rslt + end))
			end++;
		else
			handle_invalid_conv(lst, &rslt, &begin, &end);
		ft_strdelinside(&rslt, begin, end);
		if (*lst)
			*lst = (*lst)->next;
		begin++;
	}
	return (rslt);
}

int		print_result(t_conv **lst, char *rslt)
{
	int		i;
	t_conv	*lstmp;

	i = 0;
	lstmp = *lst;
	while ((*lst)->next)
	{
		if (is_null(lst) && (*lst)->conv == 'c')
		{
			while (i < (*lst)->pos)
				ft_putchar_fd(rslt[i++], 1);
			i++;
			ft_putchar_fd(0, 1);
		}
		*lst = (*lst)->next;
	}
	while (i < (int)ft_strlen(rslt))
		ft_putchar_fd(rslt[i++], 1);
	ft_strdel(&rslt);
	*lst = lstmp;
	return (i);
}

int		calc_result(t_conv **lst, char **rslt, int *i, t_fmt func)
{
	char	*tmp;
	int		j;

	j = -1;
	tmp = ft_strnew(lst_final_size(*lst) + ft_strlen(*rslt));
	tmp = ft_strcpy(tmp, "%");
	if (!(*lst)->valid && (rslt + *i + 2))
	{
		*tmp = *(rslt[*i + 1]);
		ft_strdelinside(rslt, *i, *i + 2);
	}
	if (!handle_null(lst, &tmp, *i))
		if ((*lst)->conv && !(tmp = func[(int)(*lst)->conv](lst, tmp)))
			return (0);
	while ((*lst)->attr[++j])
		if (func[(int)(*lst)->attr[j]])
			tmp = func[(int)(*lst)->attr[j]](lst, tmp);
	tmp = handle_champs(lst, tmp);
	*i += ft_strlen(tmp);
	if (handle_void(lst, &tmp, rslt, *i))
		return (1);
	*rslt = ft_addinstr(*rslt, tmp, "%", *i - ft_strlen(tmp));
	ft_strdel(&tmp);
	return (1);
}

int		fill_result(t_conv **lst, char *format)
{
	static t_fmt	func;
	char			*rslt;
	int				i;
	t_conv			*tmpc;

	i = 0;
	tmpc = *lst;
	rslt = ft_strnew(lst_sum_size(*lst, format));
	rslt = ft_strcpy(rslt, format);
	rslt = delete_conv_inside(rslt, lst);
	*lst = tmpc;
	initiate_pointer_print(func);
	while (*(rslt + i))
	{
		if (*(rslt + i) == '%')
		{
			if (!calc_result(lst, &rslt, &i, func))
				i++;
			*lst = (*lst)->next;
		}
		if (*(rslt + i) != '%')
			i++;
	}
	*lst = tmpc;
	return (print_result(lst, rslt));
}
