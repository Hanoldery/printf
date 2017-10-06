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

int		print_result(t_conv **lst, char *format)
{
	static ft_fmt	func_print;
	char			*rslt;
	char			*tmp;
	int				i;
	int				j;
	char			*fmt;

	fmt = ft_strdup(format);
	i = 0;
	j = 0;
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
			if (handle_null(lst, &tmp))
				continue;
			else
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
			rslt = putstr_in_str_if_diff(rslt, tmp, '%', i - ft_strlen(tmp));
//			printf("\t1.3 rslt__%s__ \ttmp__%s__\n", rslt, tmp);
			*lst = (*lst)->next;
		}
		i++;
	}
	ft_putstr_fd(rslt, 1);
	// Print la chaine et prie pour pas avoir d'emmerde de format...
	return (ft_strlen(rslt));
}
