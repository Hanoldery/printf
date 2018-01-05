/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:17:54 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/05 14:22:14 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** JUST IN CASE I WOULD LIKE TO MAKE THE BONUS
**	if (lstmp->pos != 0 && i--)
**		while (icp++ < lstmp->pos - 1)
**			va_arg(cp, void*);
**	else
**
**
**	t_conv	*lstmp;
**	int		i;
**	int		icp;
**	va_list	cp;
**
**	i = 0;
**	icp = 0;
**	lstmp = *lstconv;
**	while (*lstconv)
**	{
**		if ((*lstconv)->conv == '%' && ((*lstconv) = (*lstconv)->next))
**			continue;
**		//va_copy(cp, args);
**		//assign_next(lstconv, args, 0, &i);
**		//while (icp++ < i)
**		//	va_arg(cp, void*);
**		assign_arg(lstconv, args);
**		i++;
**		icp = 0;
**		*lstconv = (*lstconv)->next;
**	}
**	*lstconv = lstmp;
**	return (1);
*/

int			get_lst_conv(t_conv **lstconv, va_list args)
{
	t_conv	*lstmp;

	lstmp = *lstconv;
	while (*lstconv)
	{
		if ((*lstconv)->conv == '%' && ((*lstconv) = (*lstconv)->next))
			continue;
		assign_arg(lstconv, args);
		*lstconv = (*lstconv)->next;
	}
	*lstconv = lstmp;
	return (1);
}

int			analyze_conversion_dtls(char *s, t_conv **lstconv)
{
	char			*tmp;
	static t_fmt	func;

	initiate_pointer(func);
	tmp = (char *)s;
	tmp++;
	while (*tmp)
	{
		if (func[(int)*tmp])
		{
			tmp = func[(int)*tmp](lstconv, tmp);
			if (tmp == (char *)-1)
				return (0);
			if (!tmp)
				break ;
		}
		else
			tmp++;
	}
	return (1);
}

int			analyze_conversion(const char *format, va_list args, t_conv **lst)
{
	t_conv	*lstmp;
	char	*tmp;
	char	*del;

	tmp = ft_strdup(format);
	del = tmp;
	lstmp = *lst;
	while (*tmp)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		if (!(tmp = ft_strchr(tmp, '%')))
			break ;
		if (!analyze_conversion_dtls(tmp, lst))
			return (0);
		tmp = ft_strmchr(tmp, "diuxXeEfFaAgGcCsSpn%");
		(*lst)->next = create_lst_conv();
		((*lst)->next)->pos = (*lst)->pos + 1;
		if (*tmp == '%' && *(tmp + 1) == '%')
			tmp++;
		tmp++;
	}
	ft_strdel(&del);
	*lst = lstmp;
	return (get_lst_conv(lst, args));
}
