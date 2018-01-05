/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:25:16 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/05 14:22:06 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		initiate_pointer(t_fmt func)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * 30);
	while (i < 123)
		func[i++] = 0;
	s1 = ft_strcpy(s1, "123456789*\0");
	i = 0;
	while (*(s1 + i))
		func[(int)*(s1 + i++)] = field_fmt;
	s1 = ft_strcpy(s1, "#0+- \0");
	i = 0;
	while (*(s1 + i))
		func[(int)*(s1 + i++)] = attr_fmt;
	s1 = ft_strcpy(s1, "Llhjz\0");
	i = 0;
	while (*(s1 + i))
		func[(int)*(s1 + i++)] = length_fmt;
	func['.'] = prec_fmt;
	s1 = ft_strcpy(s1, "dDioOuUxXeEfFaAgGcCsSpn%\0");
	i = 0;
	while (*(s1 + i))
		func[(int)*(s1 + i++)] = conv_fmt;
	free(s1);
}

void		initiate_pointer_print(t_fmt func)
{
	int		i;

	i = 0;
	while (i < 123)
		func[i++] = NULL;
	func['#'] = handle_hash;
	func['+'] = handle_space_plus;
	func[' '] = handle_space_plus;
	func['o'] = handle_ou;
	func['d'] = handle_di;
	func['i'] = handle_di;
	func['u'] = handle_ou;
	func['x'] = handle_x;
	func['X'] = handle_x;
	func['c'] = handle_c;
	func['C'] = handle_c;
	func['s'] = handle_s;
	func['S'] = handle_s;
	func['p'] = handle_x;
	func['n'] = handle_n;
	func['%'] = handle_percent;
}

int			id_of_char_ifnextnot(char *str, char c, char n)
{
	int		i;

	i = 0;
	while (*(str + i) && (*(str + i) != c
				|| (*(str + i) == c && *(str + i + 1) == n)))
	{
		if (n && *(str + i) == c && *(str + i + 1) == n)
			i += 2;
		else
			i++;
	}
	if (!*(str + i))
		i = 0;
	return (i);
}
