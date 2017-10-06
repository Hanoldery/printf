/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:13:12 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/14 22:23:41 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	int		index;
	char	*str;

	str = NULL;
	index = 0;
	if (s1 && s2)
	{
		length = ft_strlen(s1) + ft_strlen(s2) + 1;
		str = (char *)malloc(sizeof(char) * length);
		if (str)
		{
			while (length-- > 0)
			{
				while (*s1)
					*(str + index++) = *s1++;
				while (*s2)
					*(str + index++) = *s2++;
			}
			*(str + index) = '\0';
		}
	}
	return (str);
}
