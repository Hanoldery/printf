/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:11:42 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/11/16 14:56:22 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_printf(const char *format,...){
	va_list	args;
	int		ret;
	t_conv	*lstconv;

	lstconv = NULL;
	lstconv = create_lst_conv();
	va_start(args, format);
//	printf("\t\t0.0 .%s.\n", format);
	analyze_conversion(format, args, &lstconv);
//	printf("\t\t1.0 .%s.\n", format);
	ret = print_result(&lstconv, (char *)format);
//	printf("\t\t2.0 .%s.\n", format);
	va_end(args);
	return (ret);
}
