/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:42:00 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/09 15:52:27 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*str1;
	size_t	index;

	index = 0;
	str1 = s1;
	while (*s1)
		s1++;
	while (*s2 && index++ < n)
		*(s1++) = *(s2++);
	*(s1++) = '\0';
	return (str1);
}
