/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 16:40:57 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/09/28 16:09:21 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmchr(const char *s1, const char *s2)
{
	char	*str1;
	char	*str2;
	char	*tmp;

	tmp = (char *)s2;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (*str2 != '\0')
	{
		while (*str1 != *str2 && *str2 != '\0')
			str2++;
		if (*str1 == *str2)
			return (str1);
		str1++;
		str2 = tmp;
	}
	return ((char *)NULL);
}
