/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:14:46 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/10 18:17:57 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	int		length;
	char	*result;

	index = 0;
	result = NULL;
	if (s)
	{
		length = ft_strlen(s);
		result = (char *)malloc(sizeof(char) * (length + 1));
		if (result)
		{
			ft_bzero(result, length);
			while (index < length)
			{
				*(result + index) = f((unsigned int)index, *(s + index));
				index++;
			}
			*(result + index) = '\0';
		}
	}
	return (result);
}
