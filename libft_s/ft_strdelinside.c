/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelinside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:29:58 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/05 18:52:23 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void			ft_strdelinside(char **str, int begin, int end)
{
	int		i;

	i = 0;
	begin++;
	while (*(*str + end))
		*(*str + begin++) = *(*str + end++);
	while (*(*str + begin))
		*(*str + begin++) = '\0';
}
