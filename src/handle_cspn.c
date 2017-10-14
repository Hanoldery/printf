/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:50:28 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/14 18:52:36 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*handle_cC(t_conv **conv, char *fmt)
{
	wint_t	str;
	char	*rslt;

	str = 0;
	rslt = NULL;
//	printf("HERE _%d_ _%d_\n", !(*conv)->sdata, !(str = *(*conv)->sdata));
//	if (!(*conv)->sdata || !(str = *(*conv)->sdata))
//		return (NULL);
//	printf("HERE\n");
	if (((*conv)->conv == 'C' || ft_strchr((*conv)->modif, 'l'))
			&& MB_CUR_MAX > 1)
	{
		rslt = ft_strdup(wchar_to_str(str));
	}
	else
	{
		rslt = ft_strnew(2);
		*rslt = (char)*(*conv)->sdata;
	}
//	printf("HERE\n");
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
//	if (!(*conv)->sdata)
//		return (NULL);
//	printf("Zero \n %c \n %s\n %d \n", (*conv)->conv, ft_strchr((*conv)->modif, 'l'), MB_CUR_MAX);
	if (((*conv)->conv == 'C' || ft_strchr((*conv)->modif, 'l'))
			&& MB_CUR_MAX > 1)
		rslt = ft_strdup(wcharstr_to_str(str));
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

char		*handle_p(t_conv **conv, char *fmt)
{
	(void)conv;
	(void)fmt;
	return (NULL);
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
