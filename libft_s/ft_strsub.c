/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:55:54 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/17 19:14:43 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		index;
	char		*str;

	index = 0;
	str = NULL;
	if (s)
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str)
		{
			ft_bzero(str, ft_strlen(str));
			while (index < len)
				*(str + index++) = *(s + start++);
			*(str + index) = '\0';
		}
	}
	return (str);
}
