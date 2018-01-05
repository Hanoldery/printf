/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:11:42 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/05 14:07:54 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		free_lst(t_conv *lstconv)
{
	t_conv		*lstmp;

	lstmp = lstconv;
	while (lstconv)
	{
		ft_strdel(&lstconv->attr);
		free(lstconv->data);
		if (lstconv->conv != 's')
			free(lstconv->sdata);
		ft_strdel(&lstconv->modif);
		lstconv = lstconv->next;
		free(lstmp);
		lstmp = lstconv;
	}
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	t_conv	*lstconv;

	lstconv = NULL;
	lstconv = create_lst_conv();
	va_start(args, format);
	if (!analyze_conversion(format, args, &lstconv))
	{
		free_lst(lstconv);
		return (0);
	}
	ret = fill_result(&lstconv, (char *)format);
	free_lst(lstconv);
	va_end(args);
	return (ret);
}
