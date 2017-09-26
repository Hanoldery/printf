/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:20:01 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/09/26 17:40:47 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*delete_conv_inside(char *fmt)
{
	char	*part1;
	char	*part2;
	int		i;
	int		j;

	j = 0;
	i = 0;
	part1 = fmt;
	part2 = fmt;
	while (*(part1 + i))
	{
		while (*(part1 + i))//&& (*(part1 + i) != '%' || *(part1 + i + 1) == '%'))
			i++;
		if (!*(part1 + i))
			return (part1);
		part1 = ft_strsub(fmt, 0, i + 1);
		part2 = fmt + i + 1;
		//printf("\t\t 0-%d : __%s__ and __%s__ from __%s__\n", i, part1, part2, fmt);
		while (!ft_strchr("diouxXeEfFgGaAcCsSpn%", *(part2 + j)))
			j++;
		part2 = ft_strsub(part2, j + 1, ft_strlen(part2));
		//printf("\t\t 0-%d : __%s__ and __%s__ from __%s__\n", i, part1, part2, fmt);
		part1 = ft_strjoinfree(part1, part2);
		j = 0;
		i++;
	}
	return (part1);
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
	printf("\t- Deleted %% inside\n");
	initiate_pointer_print(func_print);
	printf("\t- Filled pointer function\n");
	printf("\t- Before : _%s_ with attr : '%s'\n", (rslt + i), (*lst)->attr);
	while (*(rslt + i))
	{
		printf("\t%d: %c\n", i, *(rslt + i));
		if (*(rslt + i) == '%')
		{
			tmp = ft_strcpy(tmp, "%");
			tmp = handle_champs(lst, tmp);
			printf("\t- Filled pointer function\n");
			while ((*lst)->attr[j])
			{
				printf("\t- Making attr : '%c' j%d\n", (*lst)->attr[j], j);
				tmp = func_print[(*lst)->attr[j++]](lst, tmp);
			}
			printf("\t1.0 rslt__%s__ \ttmp__%s__ conv-%c-\n", rslt, tmp, (*lst)->conv);
			tmp = func_print[(*lst)->conv](lst, tmp);
			printf("\t1.2 rslt__%s__ \ttmp__%s__\n", rslt, tmp);
			//La precision sera directement gere dans les conversions concernes.
			i += ft_strlen(tmp);
			rslt = putstr_in_str_if_diff(rslt, tmp, '%', i - ft_strlen(tmp));
			printf("\t1.3 rslt__%s__ \ttmp__%s__\n", rslt, tmp);
			*lst = (*lst)->next;
		}
		i++;
	}
	ft_putstr_fd(rslt, 1);
	// Print la chaine et prie pour pas avoir d'emmerde de format...
	return (ft_strlen(rslt));
}
