/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:11:42 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/04 20:21:37 by pgerbaud         ###   ########.fr       */
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
	//printf("\n----------------------------\n");
	//printf("FT_RINTF 0\n");
	if (!analyze_conversion(format, args, &lstconv))
	{
		//printf("FT_RINTF 0.0\n");
		free_lst(lstconv);
		//free(lstconv);
		//printf("FT_RINTF 0.1\n");
		return (0);
	}
	//printf("FT_RINTF 1\n");
	ret = fill_result(&lstconv, (char *)format);
	//printf("FT_RINTF 2\n");
	free_lst(lstconv);
	//free(lstconv);
	va_end(args);
	//printf("FT_RINTF 3\n");
	return (ret);
}
