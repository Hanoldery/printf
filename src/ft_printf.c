/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:11:42 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/11/21 15:26:31 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	t_conv	*lstconv;

	lstconv = NULL;
	lstconv = create_lst_conv();
	va_start(args, format);
	analyze_conversion(format, args, &lstconv);
	ret = fill_result(&lstconv, (char *)format);
	va_end(args);
	return (ret);
}
