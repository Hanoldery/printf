/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:55:05 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/05 12:13:30 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	index;
	char	*s2;

	index = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!(s2 = ft_strnew(index + 1)))
		return (NULL);
	index = 0;
	while (*(s1 + index) != '\0')
	{
		*(s2 + index) = *(s1 + index);
		index++;
	}
	*(s2 + index) = '\0';
	return (s2);
}
