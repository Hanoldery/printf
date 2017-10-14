/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:20:01 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/05 20:19:23 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*delete_conv_inside(char *fmt)
{
	char	*rslt;
	int		begin;
	int		end;

	begin = 0;
	end = 0;
	rslt = fmt;
	while (*(rslt + begin))
	{
		while (*(rslt + begin) && *(rslt + begin) != '%')
			begin++;
		if (!*(rslt + begin))
			return (rslt);
		end = begin + 1;
		while (!ft_strchr("diouxXeEfFgGaAcCsSpn%", *(rslt + end)))
			end++;
		end++;
		ft_strdelinside(&rslt, begin, end);
		begin++;
	}
	return (rslt);
}

int		print_result2(t_conv **lst, char *rslt)
{
	int		i;

	i = 0;
//	printf("here myman rslt%d\n", ft_strlen(rslt));
	while ((*lst)->next)
	{
//		printf("here myman2 %d %d\n", is_null(lst),  (*lst)->conv == 'c');
		if (is_null(lst) && (*lst)->conv == 'c')
		{
			while (i < (*lst)->pos)
				ft_putchar_fd(rslt[i++], 1);
//			printf("About to write null _%s_\n", rslt + i);
			i++;
			ft_putchar_fd(0, 1);
		}
		*lst = (*lst)->next;
	}
	while (i < ft_strlen(rslt))
		ft_putchar_fd(rslt[i++], 1);
	return (i);
}

int		print_result(t_conv **lst, char *format)
{
	static ft_fmt	func_print;
	char			*rslt;
	char			*tmp;
	int				i;
	int				j;
	char			*fmt;
	t_conv			*tmpc;

	fmt = ft_strdup(format);
	i = 0;
	j = 0;
	tmpc = *lst;
	tmp = (char *)malloc(sizeof(char) * 2);
	rslt = delete_conv_inside(fmt + i);
//	printf("\t- Deleted %% inside\n");
	initiate_pointer_print(func_print);
//	printf("\t- Filled pointer function\n");
//	printf("\t- Before : _%s_ with attr : '%s'\n", (rslt + i), (*lst)->attr);
	while (*(rslt + i))
	{
		if (*(rslt + i) == '%')
		{
			tmp = ft_strcpy(tmp, "%");
//			printf("\t- Filled pointer function _%s_\n", rslt + i);
//			printf("\t1.0 rslt__%s__ \ttmp__%s__ conv-%c-\n", rslt, tmp, (*lst)->conv);
			if (!handle_null(lst, &tmp, i))
			{
				if (!(tmp = func_print[(*lst)->conv](lst, tmp)))
				{
					*lst = (*lst)->next;
					i++;
					continue;
				}
			}
			while ((*lst)->attr[j])
			{
//				printf("\t- Making attr : '%c' j%d\n", (*lst)->attr[j], j);
				if (func_print[(*lst)->attr[j]])
					tmp = func_print[(*lst)->attr[j]](lst, tmp);
				j++;
			}
			tmp = handle_champs(lst, tmp);
//			printf("\t1.2 rslt__%s__ \ttmp__%s__\n", rslt, tmp);
			//La precision sera directement gere dans les conversions concernes.
			i += ft_strlen(tmp);
			if (!handle_void(lst, &tmp, &rslt, i))
				rslt = putstr_in_str_if_diff(rslt, tmp, '%', i - ft_strlen(tmp));
//			printf("\t1.3 rslt__%s__ \ttmp__%s__\n", rslt, tmp);
			*lst = (*lst)->next;
		}
		//if (*(rslt + i) != '%')
		j = 0;
		i++;
	}
	*lst = tmpc;
	// Print la chaine et prie pour pas avoir d'emmerde de format...
	return (print_result2(lst, rslt));
}
