/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:30:04 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/18 12:25:23 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		index;
	size_t		index2;

	index = 0;
	index2 = n;
	if (s1 && s2)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (1);
		while (*s1 && *s2 && n-- > 0 && *s1++ == *s2++)
			index++;
		if ((!*s1 || !*s2) && *(s1 - 1) == *(s2 - 1))
			return (1);
		if (index2 == index || (!*s1 && !*s2))
			return (1);
	}
	return (0);
}
