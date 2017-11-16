/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:50:28 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/11/16 18:08:40 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*handle_cC(t_conv **conv, char *fmt)
{
	wint_t	str;
	char	*rslt;

//	printf("\t\t\tHANDLE_C .%d. .%d.\n", MB_CUR_MAX, (ft_strchr((*conv)->modif, 'l') && MB_CUR_MAX > 1));
	str = (wint_t)(*conv)->sdata[0];
	rslt = NULL;
	if (ft_strchr((*conv)->modif, 'l') && MB_CUR_MAX > 1)
	{
		setlocale(LC_ALL, "");
//		printf("\t\t\tHANDLE_C.Y .%d.\n", str);
		rslt = ft_strdup(wchar_to_str(str));
	}
	else
	{
//		printf("\t\t\tHANDLE_C.N .%C.%s.\n", str,rslt);
		rslt = ft_strnew(2);
		*rslt = (char)*(*conv)->sdata;
	}
//	printf("\t\t\tHANDLE_C .%s.\n", rslt);
	fmt = ft_addinstr(fmt, rslt, "%", 0);
	return (fmt);
}

char		*handle_sS(t_conv **conv, char *fmt)
{
	wint_t	*str;
	char	*rslt;
	int		max;

	max = (*conv)->precision;
	str = (*conv)->sdata;
	rslt = NULL;
//	printf("\t\tsS %d%c\n", MB_CUR_MAX, (*conv)->conv);
	if (((*conv)->conv == 'S' || ft_strchr((*conv)->modif, 'l'))
			&& MB_CUR_MAX > 1)
		rslt = ft_strdup(wcharstr_to_str(str, conv));
	else
		rslt = ft_strdup((char *)(*conv)->sdata);
	if (ft_strlen(rslt) > (*conv)->precision && (*conv)->prec_changed)
		*(rslt + (*conv)->precision ) = '\0';
	if (ft_strlen(rslt) == 0)
	{
		rslt = ft_strnew(2);
		*rslt = (char)0;
		*(rslt + 1) = '\0';
	}
	else
		rslt = ft_addinstr(fmt, rslt, "%", 0);
	return (rslt);
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
