/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:11:42 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/12/07 16:04:55 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		free_lst(t_conv *lstconv)
{
	while (lstconv)
	{
//		free(lstconv->attr);
//		free(lstconv->data);
//		free(lstconv->sdata);
//		free(lstconv->conv);
//		free(lstconv->modif);
		lstconv = lstconv->next;
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
	//printf("\n----------------------------\n");
	//printf("FT_RINTF 0\n");
	if (!analyze_conversion(format, args, &lstconv))
	{	
		//printf("FT_RINTF 0.0\n");
		free_lst(lstconv);
		free(lstconv);
		//printf("FT_RINTF 0.1\n");
		return (0);
	}
	//printf("FT_RINTF 1\n");
	ret = fill_result(&lstconv, (char *)format);
	//printf("FT_RINTF 2\n");
	free_lst(lstconv);
	free(lstconv);
	va_end(args);
	//printf("FT_RINTF 3\n");
	return (ret);
}
