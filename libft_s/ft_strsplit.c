/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:18:44 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/16 19:38:21 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		nbr;

	nbr = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		nbr++;
		while (*s != c && *s)
			s++;
	}
	if (*(s - 1) == c)
		nbr--;
	return (nbr);
}

static int	word_length(char *s, char c)
{
	int		length;

	length = 1;
	while (*s == c)
		s++;
	while (*s != c && *s++)
		length++;
	return (length);
}

char		**ft_strsplit(char const *s, char c)
{
	int		index;
	int		index2;
	char	**tab;

	if (!s || !c)
		return (NULL);
	index = 0;
	index2 = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	while (count_words(s, c) > 0)
	{
		while (*s == c)
			s++;
		if (!(tab[index] = (char *)malloc(sizeof(char) *
				(word_length((char *)s, c) + 1))))
			return (NULL);
		while (*s != c && *s)
			tab[index][index2++] = *s++;
		tab[index][index2] = '\0';
		index2 = 0;
		index++;
	}
	tab[index] = NULL;
	return (tab);
}
