/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelinside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:29:58 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/12/07 19:58:32 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strdelinside(char **str, int begin, int end)
{
	begin++;
	while (*(*str + end))
		*(*str + begin++) = *(*str + end++);
	while (*(*str + begin))
		*(*str + begin++) = '\0';
}
