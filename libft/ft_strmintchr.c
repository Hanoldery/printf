/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmintchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:27:33 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/11/28 16:28:08 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strmintchr(const char *s1, const char *s2)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (char *)s2;
	while (s2[j] != '\0')
	{
		while (s1[i] != s2[j] && s2[j] != '\0')
			j++;
		if (s1[i] == s2[j])
			return (i);
		i++;
		j = 0;
	}
	return (0);
}
