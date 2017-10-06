/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:56:56 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/10 18:15:29 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				*(result + index) = f(*(s + index));
				index++;
			}
			*(result + index) = '\0';
		}
	}
	return (result);
}
