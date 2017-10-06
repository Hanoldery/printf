/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:53:30 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/17 18:59:45 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		index;
	int		length;

	if (s && f)
	{
		length = ft_strlen(s);
		index = 0;
		while (index < length)
		{
			f((unsigned int)index, s + index);
			index++;
		}
	}
}
