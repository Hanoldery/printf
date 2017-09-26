/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_w.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:21:29 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/09/26 16:34:31 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			w_size(wchar_t wchar)
{
	if (wchar <= 0x7F)
		return (1);
	if (wchar <= 0x7FF)
		return (2);
	if (wchar <= 0xFFFF)
		return (3);
	if (wchar <= 0x10FFFF)
		return (4);
	return (0);
}

char		*wchar_to_str(wchar_t wchar)
{
	char	*str;

	str = ft_strnew(w_size(wchar));
	if (w_size(wchar) == 1)
		*str = wchar;
	else if (w_size(wchar) == 2)
		*str = (wchar >> 6) + 0xC0;
	else if (w_size(wchar) == 3)
	{
		*str = (wchar >> 12) + 0xE0;
		*(str + 1) = ((wchar >> 6) & 0x3F) + 0x80;
	}
	else if (w_size(wchar) == 4)
	{
		*str = (wchar >> 18) + 0xF0;
		*(str + 1) = ((wchar >> 12) & 0x3F) + 0x80;
		*(str + 2) = ((wchar >> 6) & 0x3F) + 0x80;
	}
	*(str + w_size(wchar) - 1) = (wchar & 0x3F) + 0x80;
	return (str);
}

char		*wcharstr_to_str(wchar_t *swchar)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	while (*(swchar + i))
	{
		str = ft_strjoinfree(str, wchar_to_str(*(swchar + i)));
		//printf("\t\tWchar Str %s\n", str);
		i += w_size(*(swchar + i));
	}
	return (str);
}
