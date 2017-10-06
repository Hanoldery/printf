/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:11:42 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/05 19:02:44 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_printf(const char *format,...){
	va_list	args;
	int		ret;
	t_conv	*lstconv;

	lstconv = NULL;
//	printf("-----------------\n");
	lstconv = create_lst_conv();
	va_start(args, format);
	analyze_conversion(format, args, &lstconv);
	//	printf("1.0 \n");
	ret = print_result(&lstconv, (char *)format);
//	printf("\n2.0 \n");
	va_end(args);
	return (ret);
}
