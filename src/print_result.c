/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:20:01 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/11/21 16:21:13 by pgerbaud         ###   ########.fr       */
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
		while (*(rslt + begin) && *(rslt + begin) != '%')
			begin++;
		if (!*(rslt + begin))
			return (rslt);
		end = begin + 1;
		while (!ft_strchr("diouxXeEfFgGaAcCsSpn%", *(rslt + end))
				&& ft_strchr(" -+0123456789#*$.hjzlL", *(rslt + end)))
			end++;
		if (ft_strchr(" -+0123456789#*$.hjzlLdDioOuUxXeEfFgGaAcCsSpn%",
					*(rslt + end))
				&& *(rslt + end))
			end++;
		else
			handle_invalid_conv(lst, &rslt, &begin, &end);
		ft_strdelinside(&rslt, begin, end);
		begin++;
	}
	return (rslt);
}

int		print_result(t_conv **lst, char *rslt)
{
	int		i;

	i = 0;
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
	while (i < ft_strlen(rslt))
		ft_putchar_fd(rslt[i++], 1);
	return (i);
}

int		calc_result(t_conv **lst, char **rslt, int *i, ft_fmt func)
{
	char	*tmp;
	int		j;

	j = -1;
	tmp = (char *)malloc(sizeof(char) * 2);
	tmp = ft_strcpy(tmp, "%");
	if (!(*lst)->valid && (rslt + *i + 2))
	{
		*tmp = *(rslt[*i + 1]);
		ft_strdelinside(rslt, *i, *i + 2);
	}
	if (!handle_null(lst, &tmp, *i))
		if ((*lst)->conv && !(tmp = func[(*lst)->conv](lst, tmp)))
			return (0);
	while ((*lst)->attr[++j])
		if (func[(*lst)->attr[j]])
			tmp = func[(*lst)->attr[j]](lst, tmp);
	tmp = handle_champs(lst, tmp);
	*i += ft_strlen(tmp);
	if (handle_void(lst, &tmp, rslt, *i))
		return (1);
	*rslt = ft_addinstr(*rslt, tmp, "%", *i - ft_strlen(tmp));
	return (1);
}

int		fill_result(t_conv **lst, char *format)
{
	static ft_fmt	func;
	char			*rslt;
	int				i;
	char			*fmt;
	t_conv			*tmpc;

	fmt = ft_strdup(format);
	i = 0;
	tmpc = *lst;
	rslt = delete_conv_inside(fmt + i, lst);
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
