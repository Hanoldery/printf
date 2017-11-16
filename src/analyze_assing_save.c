/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 18:19:59 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/22 18:23:53 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		assign_args_unsigned(t_conv **lstconv, va_list args)
{
	if (ft_strchr("ouxX", (*lstconv)->conv))
	{
		if ((*lstconv)->modif[0] == 'h' && (*lstconv)->modif[1] == 'h')
			(*lstconv)->data[0] = (char)va_arg(args, int);
		else if ((*lstconv)->modif[0] == 'h')
			(*lstconv)->data[0] = (short)va_arg(args, int);
		else if ((*lstconv)->modif[0] == 'z')
			(*lstconv)->data[0] = va_arg(args, size_t);
		else if ((*lstconv)->modif[0] == 'l')
			(*lstconv)->data[0] = (ft_strchr("di", (*lstconv)->conv)) ?
				va_arg(args, long) : va_arg(args, unsigned long);
		else if ((*lstconv)->modif[0] == 'l' && (*lstconv)->modif[1] == 'l')
			(*lstconv)->data[0] = (ft_strchr("di", (*lstconv)->conv)) ?
				va_arg(args, long long) : va_arg(args, unsigned long long);
		else if ((*lstconv)->modif[0] == 'j')
			(ft_strchr("di", (*lstconv)->conv)) ?
				(*lstconv)->data[0] = va_arg(args, intmax_t)
				: ((*lstconv)->data[0] = va_arg(args, uintmax_t));
		else if (ft_strchr("di", (*lstconv)->conv))
			(*lstconv)->data[0] = va_arg(args, int);
		else
			(*lstconv)->data[0] = va_arg(args, unsigned int);
	}
}

void		assign_args(t_conv **lstconv, va_list args)
{
	if (ft_strchr("diouxX", (*lstconv)->conv))
	{
		if ((*lstconv)->modif[0] == 'h' && (*lstconv)->modif[1] == 'h')
			(*lstconv)->data[0] = (char)va_arg(args, int);
		else if ((*lstconv)->modif[0] == 'h')
			(*lstconv)->data[0] = (short)va_arg(args, int);
		else if ((*lstconv)->modif[0] == 'z')
			(*lstconv)->data[0] = va_arg(args, size_t);
		else if ((*lstconv)->modif[0] == 'l')
			(*lstconv)->data[0] = (ft_strchr("di", (*lstconv)->conv)) ?
				va_arg(args, long) : va_arg(args, unsigned long);
		else if ((*lstconv)->modif[0] == 'l' && (*lstconv)->modif[1] == 'l')
			(*lstconv)->data[0] = (ft_strchr("di", (*lstconv)->conv)) ?
				va_arg(args, long long) : va_arg(args, unsigned long long);
		else if ((*lstconv)->modif[0] == 'j')
			(ft_strchr("di", (*lstconv)->conv)) ?
				(*lstconv)->data[0] = va_arg(args, intmax_t)
				: ((*lstconv)->data[0] = va_arg(args, uintmax_t));
		else if (ft_strchr("di", (*lstconv)->conv))
			(*lstconv)->data[0] = va_arg(args, int);
		else
			(*lstconv)->data[0] = va_arg(args, unsigned int);
	}
	if (ft_strchr("cs", (*lstconv)->conv))
	{
		if ((*lstconv)->conv == 'c')
			((*lstconv)->modif[0] == 'l') ?
				((*lstconv)->sdata[0] = va_arg(args, wint_t)) :
				((*lstconv)->sdata[0] = va_arg(args, int));
		else if ((*lstconv)->conv == 's')
		{
			((*lstconv)->modif[0] == 'l') ?
				((*lstconv)->sdata = (wint_t *)va_arg(args, wchar_t *))
				: ((*lstconv)->sdata = (wint_t *)va_arg(args, char *));
			if ((*lstconv)->sdata == (int *)0xa)
				(*lstconv)->sdata = NULL;
		}
	}
	if ((*lstconv)->conv == 'p')
		(*lstconv)->data[0] = (int)va_arg(args, void *);
}

void		assign_nexts(t_conv **lst, va_list args, int j, int *i)
{
	va_list cp;

	if (!(*lst)->champs_changed && (*lst)->champs == -1)
		*i = ((*lst)->champs = va_arg(cp, unsigned int)) ? *++i: *i;
	if (!(*lst)->prec_changed && (*lst)->precision == -1)
		*i = ((*lst)->precision = va_arg(cp, unsigned int)) ? *++i: *i;
	if ((*lst)->champs < 0)
	{
		va_copy(cp, args);
		while (j++ < *i)
			va_arg(cp, void *);
		(*lst)->champs = va_arg(cp, int);
		va_end(cp);
	}
	j = 0;
	if ((*lst)->precision < 0)
	{
		va_copy(cp, args);
		while (j++ < *i)
			va_arg(cp, void *);
		(*lst)->precision = va_arg(cp, int);
		va_end(cp);
	}
}

