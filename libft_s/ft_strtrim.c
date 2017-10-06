/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:11:34 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/16 19:44:58 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		length;
	char	*result;

	if (!s)
		return (NULL);
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s)
		s++;
	length = ft_strlen(s);
	while ((*(s + length - 1) == ' ' || *(s + length - 1) == '\n'
				|| *(s + length - 1) == '\t') && *s)
		length--;
	result = ft_strsub(s, 0, length);
	return (result);
}
