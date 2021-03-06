/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 18:19:59 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/05 14:05:35 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		assign_arg_unsigned(t_conv **lstconv, va_list args)
{
	if ((*lstconv)->modif[0] == 'h' && (*lstconv)->modif[1] == 'h')
		(*lstconv)->udata = (unsigned char)va_arg(args, int);
	else if ((*lstconv)->modif[0] == 'h')
		(*lstconv)->udata = (unsigned short)va_arg(args, int);
	else if ((*lstconv)->modif[0] == 'z')
		(*lstconv)->udata = va_arg(args, ssize_t);
	else if ((*lstconv)->modif[0] == 'l')
		(*lstconv)->udata = va_arg(args, unsigned long);
	else if ((*lstconv)->modif[0] == 'l' && (*lstconv)->modif[1] == 'l')
		(*lstconv)->udata = va_arg(args, unsigned long long);
	else if ((*lstconv)->modif[0] == 'j')
		(*lstconv)->udata = va_arg(args, uintmax_t);
	else
		(*lstconv)->udata = va_arg(args, unsigned int);
}

void		assign_arg_signed(t_conv **lstconv, va_list args)
{
	if ((*lstconv)->modif[0] == 'h' && (*lstconv)->modif[1] == 'h')
		(*lstconv)->data[0] = (char)va_arg(args, int);
	else if ((*lstconv)->modif[0] == 'h')
		(*lstconv)->data[0] = (short)va_arg(args, int);
	else if ((*lstconv)->modif[0] == 'z')
		(*lstconv)->data[0] = va_arg(args, size_t);
	else if ((*lstconv)->modif[0] == 'l')
		(*lstconv)->data[0] = (long)va_arg(args, long);
	else if ((*lstconv)->modif[0] == 'l' && (*lstconv)->modif[1] == 'l')
		(*lstconv)->data[0] = (long long)va_arg(args, long long);
	else if ((*lstconv)->modif[0] == 'j')
		(*lstconv)->data[0] = (intmax_t)va_arg(args, intmax_t);
	else
		(*lstconv)->data[0] = va_arg(args, int);
}

void		assign_arg_special(t_conv **lstconv, va_list args)
{
	if (ft_strchr("cs", (*lstconv)->conv))
	{
		if ((*lstconv)->conv == 'c')
		{
			((*lstconv)->modif[0] == 'l') ?
				((*lstconv)->sdata[0] = va_arg(args, wint_t)) :
				((*lstconv)->sdata[0] = va_arg(args, int));
		}
		else if ((*lstconv)->conv == 's')
		{
			free((*lstconv)->sdata);
			((*lstconv)->modif[0] == 'l') ?
				((*lstconv)->sdata = (wint_t *)va_arg(args, wchar_t *)) :
				((*lstconv)->sdata = (wint_t *)va_arg(args, char *));
			if ((*lstconv)->sdata == (int *)0xa)
				(*lstconv)->sdata = NULL;
		}
	}
	if ((*lstconv)->conv == 'p')
		(*lstconv)->udata = (uintmax_t)va_arg(args, void *);
}

/*
**	if (!(*lst)->champs_changed && (*lst)->champs == -1)
**		*i = ((*lst)->champs = va_arg(cp, unsigned int)) ? *++i : *i;
**	if (!(*lst)->prec_changed && (*lst)->precision == -1)
**		*i = ((*lst)->precision = va_arg(cp, unsigned int)) ? *++i : *i;
*/

void		assign_next(t_conv **lst, va_list args, int j, int *i)
{
	va_list cp;

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

void		assign_arg(t_conv **conv, va_list args)
{
	if (ft_strchr("dDi", (*conv)->conv))
		assign_arg_signed(conv, args);
	else if (ft_strchr("oOuUxX", (*conv)->conv))
		assign_arg_unsigned(conv, args);
	else
		assign_arg_special(conv, args);
}
