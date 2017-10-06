/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:31:07 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/09 14:41:48 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int		index;

	index = -1;
	while (*(src + ++index))
		*(dst + index) = *(src + index);
	*(dst + index) = '\0';
	return (dst);
}
