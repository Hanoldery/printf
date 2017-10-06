/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:23:12 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/17 19:00:41 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t		length;
	size_t		index;

	index = 0;
	if (s1 && s2)
	{
		length = ft_strlen(s1);
		if (length == ft_strlen(s2))
		{
			while (*s1 && *s2)
				if (*s1++ == *s2++)
					index++;
			if (length == index)
				return (1);
		}
	}
	return (0);
}
