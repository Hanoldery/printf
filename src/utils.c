/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:25:16 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/14 20:05:54 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_conv		*create_lst_conv()
{
	t_conv	*nlst;

	if(!(nlst = (t_conv *)malloc(sizeof(t_conv))))
		return (NULL);
	nlst->next = NULL;
	nlst->pos = 0;
	nlst->attr = ft_strnew(5);
	nlst->data = (intmax_t *)malloc(sizeof(intmax_t));
	*nlst->data = 0;
	nlst->sdata = (wint_t *)malloc(sizeof(wint_t));
	*nlst->sdata = 0;
	nlst->udata = 0;
	nlst->champs = 0;
	nlst->precision = 0;
	nlst->prec_changed = 0;
	nlst->champs_changed = 0;
	nlst->conv = (char)malloc(sizeof(char));
	nlst->conv = '\0';
	nlst->modif = ft_strnew(2);
	return (nlst);
}

void		initiate_pointer(ft_fmt func)
{
	char	*s1;
	int		i;

	while (i < 123)
		func[i++] = 0;
	s1 = ft_strdup("123456789*\0");
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
	// TODO free(s1);
}

void	initiate_pointer_print(ft_fmt func)
{
	func['#'] = handle_hash;
//	func['0'] = handle_zero;
	func['+'] = handle_space_plus;
	func[' '] = handle_space_plus;
	func['d'] = handle_diu;
	func['o'] = handle_o;
	func['u'] = handle_diu;
	func['x'] = handle_xX;
	func['X'] = handle_xX;
	func['e'] = handle_eE;
	func['E'] = handle_eE;
	func['f'] = handle_fF;
	func['F'] = handle_fF;
	func['g'] = handle_gG;
	func['G'] = handle_gG;
	func['a'] = handle_aA;
	func['A'] = handle_aA;
	func['c'] = handle_cC;
	func['C'] = handle_cC;
	func['s'] = handle_sS;
	func['S'] = handle_sS;
	func['p'] = handle_p;
	func['n'] = handle_n;
	func['%'] = handle_percent;
}

char		*ft_addinstr(char *dst, char *src, char *eq, int index)
{
	char	*rslt;

	rslt = ft_strnew(ft_strlen(dst) + ft_strlen(src) + 1);
/*	if (c && ft_strchr(c, *(dst + i)) && ft_strlen(a) == 1)
	{
		*(dst + i) = *a;
//		printf("\t\tonly one %d %s %s\n", i, dst, a);
		return (dst);
	}
	else */
	if (eq && ft_strchr(eq, *(dst + index)))
	{
//		printf("\tADD eq\n");
		while (*(dst + index) && *src && ft_strchr(eq, *(dst + index)))
		{
			*(dst + index++) = *(src++);
			if (*(dst + index) == '%')
				break;
//			printf("\tADD eq DST%s SRC%s\n", dst, src);
		}
	}
	if (dst && *dst)
	{
//		printf("\tADD rest DST_%s_  SRC_%s_  I%d -->", dst, src, index);
		ft_strncat(rslt, dst, index);
		ft_strcat(rslt, src);
		ft_strcat(rslt, dst + index);
//		printf("%s\n", rslt);
		//TODO free(dst);
	}
	else 
	{
		rslt = ft_strcat(rslt, src);
	}
	return (rslt);
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
