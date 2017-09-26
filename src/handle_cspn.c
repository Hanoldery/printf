/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:50:28 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/09/26 17:20:20 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*handle_cC(t_conv **conv, char *fmt)
{
	wint_t	str;
	char	*rslt;

	str = *((*conv)->sdata);
	rslt = NULL;
	if (((*conv)->conv == 'C' || ft_strchr((*conv)->modif, 'l'))
			&& MB_CUR_MAX > 1)
		rslt = ft_strdup(wchar_to_str(str));
	else
		*rslt = (char)*((*conv)->sdata);
	fmt = putstr_in_str_if_diff(fmt, rslt, '%', 0);
	return (fmt);
}

char		*handle_sS(t_conv **conv, char *fmt)
{
	wint_t	*str;
	char	*rslt;

	str = (*conv)->sdata;
	rslt = NULL;
	if (((*conv)->conv == 'C' || ft_strchr((*conv)->modif, 'l'))
			&& MB_CUR_MAX > 1)
		rslt = ft_strdup(wcharstr_to_str(str));
	else
		*rslt = (char)*((*conv)->sdata);
	fmt = putstr_in_str_if_diff(fmt, rslt, '%', 0);
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
