/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:25:16 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/11/21 16:29:09 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_conv		*create_lst_conv(void)
{
	t_conv	*nlst;

	if (!(nlst = (t_conv *)malloc(sizeof(t_conv))))
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
	nlst->valid = 1;
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
	char	*rslt;

	rslt = ft_strnew(ft_strlen(dst) + ft_strlen(src) + 1);
	if (eq && ft_strchr(eq, *(dst + index)))
	{
		while (*(dst + index) && *src && ft_strchr(eq, *(dst + index)))
		{
			*(dst + index++) = *(src++);
			if (*(dst + index) == '%')
				break ;
		}
	}
	if (dst && *dst)
	{
		ft_strncat(rslt, dst, index);
		ft_strcat(rslt, src);
		ft_strcat(rslt, dst + index);
	}
	else
		rslt = ft_strcat(rslt, src);
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
