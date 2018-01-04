/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:50:28 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/04 20:19:41 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*handle_c(t_conv **conv, char *fmt)
{
	wint_t	str;
	char	*rslt;

	str = (wint_t)(*conv)->sdata[0];
	rslt = NULL;
	if (ft_strchr((*conv)->modif, 'l') && MB_CUR_MAX > 1)
		rslt = wchar_to_str(str);
	else
	{
		rslt = ft_strnew(2);
		*rslt = (char)*(*conv)->sdata;
	}
	fmt = ft_addinstr(fmt, rslt, "%", 0);
	ft_strdel(&rslt);
	return (fmt);
}

char		*handle_s(t_conv **conv, char *fmt)
{
	wint_t	*str;
	char	*rslt;
	int		max;

	//printf("HANDLE_S 0 fmt.%p\n", fmt);
	max = (*conv)->precision;
	str = (*conv)->sdata;
	rslt = NULL;
	if (((*conv)->conv == 'S' || ft_strchr((*conv)->modif, 'l'))
			&& MB_CUR_MAX > 1)
		rslt = wcharstr_to_str(str, conv);
	else
		rslt = ft_strdup((char *)(*conv)->sdata);
	if (ft_strlen(rslt) > (*conv)->precision && (*conv)->prec_changed)
		*(rslt + (*conv)->precision) = '\0';
	//printf("HANDLE_S 1 fmt.%p _%s_ %d\n", rslt, rslt, ft_strlen(rslt));
	if (ft_strlen(rslt) == 0)
	{
		//rslt = ft_strnew(2);
		*fmt = 0;
		*(fmt + 1) = '\0';
		//*rslt = (char)0;
		//*(rslt + 1) = '\0';
		//printf("HANDLE_S 1.0 fmt.%p\n", fmt);
	}
	else
		fmt = ft_addinstr(fmt, rslt, "%", 0);
	//printf("HANDLE_S 2 rslt.%p %d\n", rslt, ft_strlen(rslt));
	ft_strdel(&rslt);
	return (fmt);
}

char		*handle_n(t_conv **conv, char *fmt)
{
	(void)conv;
	(void)fmt;
	return (NULL);
}

char		*handle_percent(t_conv **conv, char *fmt)
{
	(void)conv;
	return (fmt);
}
