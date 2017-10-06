/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:12:57 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/09 23:26:32 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		index;
	int		index2;
	int		littlelen;

	index = 0;
	index2 = 0;
	littlelen = ft_strlen(little);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (*(big + index))
	{
		while (*(big + index + index2) == *(little + index2)
				&& index2 < littlelen)
			index2++;
		if (index2 == littlelen)
			return ((char *)(big + index));
		index2 = 0;
		index++;
	}
	return (NULL);
}
