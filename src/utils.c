/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:25:16 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/12/07 18:12:04 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		initiate_pointer(ft_fmt func)
{
	char	*s1;
	int		i;

	s1 = (char *)malloc(sizeof(char) * 30);
	while (i < 123)
		func[i++] = 0;
	s1 = ft_strcpy(s1, "123456789*\0");
	i = 0;
	while (*(s1 + i))
		func[*(s1 + i++)] = field_fmt;
	s1 = ft_strcpy(s1, "#0+- ");
	i = 0;
	while (*(s1 + i))
		func[*(s1 + i++)] = attr_fmt;
	s1 = ft_strcpy(s1, "Llhjz");
	i = 0;
	while (*(s1 + i))
		func[*(s1 + i++)] = length_fmt;
	func['.'] = prec_fmt;
	s1 = ft_strcpy(s1, "dDioOuUxXeEfFaAgGcCsSpn%");
	i = 0;
	while (*(s1 + i))
		func[*(s1 + i++)] = conv_fmt;
	free(s1);
}

void		initiate_pointer_print(ft_fmt func)
{
	func['#'] = handle_hash;
	func['+'] = handle_space_plus;
	func[' '] = handle_space_plus;
	func['o'] = handle_ou;
	func['d'] = handle_di;
	func['i'] = handle_di;
	func['u'] = handle_ou;
	func['x'] = handle_x;
	func['X'] = handle_x;
	func['e'] = handle_e;
	func['E'] = handle_e;
	func['f'] = handle_f;
	func['F'] = handle_f;
	func['g'] = handle_g;
	func['G'] = handle_g;
	func['a'] = handle_a;
	func['A'] = handle_a;
	func['c'] = handle_c;
	func['C'] = handle_c;
	func['s'] = handle_s;
	func['S'] = handle_s;
	func['p'] = handle_x;
	func['n'] = handle_n;
	func['%'] = handle_percent;
}

char		*ft_addinstr(char *dst, char *src, char *eq, int index)
{
	int		i;
	int		j;
	int		plus;
	int		max;

	plus = 0;
	max = ft_strlen(dst);
	j = ft_strlen(dst) - index + 1;
	i = -1;
	//printf("\nADDINSTR 0 \tdst_%s_ \tsrc_%s_ eq_%s_ index_%d_\n", dst, src, eq, index);
	if (eq && ft_strchr(eq, *(dst + index)))
	{
		//printf("\tADDINSTR 1 src_%s_\n", src);
		*(dst + index) = *src;
		src++;
		plus++;
		//printf("\tADDINSTR 2 src_%s_\n", src);
	}
	if (dst && *dst)
	{
		//printf("\tADDINSTR 3 src_%s_ src.%p dst.%p\n", src, src, dst);
		while (++i < ft_strlen(src))
		{
			//printf("\tADDINSTR 3.0 BCL i.%d. dst_%s_\n", i, dst);
			while (--j >= 0)
			{
				//printf("\tADDINSTR 3.0.0 BCL _%s_", src);
				//printf("\tindex.%d i.%d j.%d\tsrc.%p total.%p\n", index, i, j, src, dst + index + i + j + 1);
				dst[index + i + j + 1] = dst[index + i + j];
			}
			j = max - index + 1;
			//printf("\tADDINSTR 3.1 BCL i.%d. src_%s_\n\n", i, src);
		}
		//printf("\tADDINSTR 4 src_%s_ %p lsrc%d\n", src, dst + index + plus, ft_strlen(src));
		ft_memcpy(dst + index + plus, src, ft_strlen(src));
	}
	else
		dst = ft_strcat(dst, src);
	//printf("ADDINSTR RSLT rslt_%s_\n", dst);
	return (dst);
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
