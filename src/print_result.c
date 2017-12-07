/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:20:01 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/12/07 19:00:01 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*delete_conv_inside(char *rslt, t_conv **lst)
{
	int		begin;
	int		end;

	begin = 0;
	end = 0;
			t_conv *tmp;
			tmp = *lst;
			while (tmp)
			{
				//printf("--- DELETE_CONV %d\n\t%p %p __%s__\n\n", tmp->pos, tmp->sdata, tmp->data, rslt);
				tmp = tmp->next;
			}
	while (*(rslt + begin))
	{
		//printf("\tSEG PRINT DEL 0\n");
		while (*(rslt + begin) != '%')
			if (!*(rslt + begin++))
				return (rslt);
		//printf("\tSEG PRINT DEL 1\n");
		end = begin + 1;
		//printf("\tSEG PRINT DEL 2\n");
		while (!ft_strchr("diouxXeEfFgGaAcCsSpn%", *(rslt + end))
				&& ft_strchr(" -+0123456789#*$.hjzlL", *(rslt + end)))
			end++;
		//printf("\tSEG PRINT DEL 3\n");
		if (ft_strchr(" -+0123456789#*$.hjzlLdDioOuUxXeEfFgGaAcCsSpn%",
					*(rslt + end)) && *(rslt + end))
			end++;
		else
			handle_invalid_conv(lst, &rslt, &begin, &end);
		//printf("\tSEG PRINT DEL 4\n");
		ft_strdelinside(&rslt, begin, end);
		//printf("\tSEG PRINT DEL 5.%d _%s_ \n\t%p\n", begin, rslt, *lst);
		//printf("\tSEG PRINT DEL 5 %si %d %p\n%p\n", rslt, begin, *lst, (*lst)->next);
		if (*lst)
			*lst = (*lst)->next;
		begin++;
		//printf("\tSEG PRINT DEL 6 %si %d\n", rslt, begin);
	}
	//printf("\tSEG PRINT DEL 7 %si %d\n", rslt, begin);
	return (rslt);
}

int		print_result(t_conv **lst, char *rslt)
{
	int		i;

	i = 0;
	//printf("\tSEG PRINT RSLT 0\n");
	while ((*lst)->next)
	{
		//printf("\tSEG PRINT RSLT 0.0\n");
		if (is_null(lst) && (*lst)->conv == 'c')
		{
			//printf("\tSEG PRINT RSLT 0.0.0\n");
			while (i < (*lst)->pos)
				ft_putchar_fd(rslt[i++], 1);
			i++;
			ft_putchar_fd(0, 1);
			//printf("\tSEG PRINT RSLT 0.0.1\n");
		}
		//printf("\tSEG PRINT RSLT 0.1\n");
		*lst = (*lst)->next;
	}
	//printf("\tSEG PRINT RSLT 1\n");
	while (i < ft_strlen(rslt))
		ft_putchar_fd(rslt[i++], 1);
	//printf("\tSEG PRINT RSLT 2\n");
	free(rslt);
	return (i);
}

int		calc_result(t_conv **lst, char **rslt, int *i, ft_fmt func, t_conv *ltmp)
{
	char	*tmp;
	int		j;

	j = -1;
	//printf("\tSEG PRINT 0\n");
	tmp = (char *)malloc(sizeof(char) * (lst_final_size(*lst)
				+ ft_strlen(*rslt)));
	//printf("\tCALC_RESULT 0 %d\n", lst_final_size(*lst) + ft_strlen(*rslt));
	tmp = ft_strcpy(tmp, "%");
	//printf("\tCALC_RESULT 0.0 %p\n", tmp);
	if (!(*lst)->valid && (rslt + *i + 2))
	{
		*tmp = *(rslt[*i + 1]);
		ft_strdelinside(rslt, *i, *i + 2);
	}
	//printf("\tSEG PRINT 2\n");
	if (!handle_null(lst, &tmp, *i))
		if ((*lst)->conv && !(tmp = func[(*lst)->conv](lst, tmp)))
			return (0);
	//printf("\tCALC_RESULT 0.1 %s\n", tmp);
	while ((*lst)->attr[++j])
		if (func[(*lst)->attr[j]])
			tmp = func[(*lst)->attr[j]](lst, tmp);
	tmp = handle_champs(lst, tmp);
	*i += ft_strlen(tmp);
	if (handle_void(lst, &tmp, rslt, *i))
		return (1);
	//printf("\tCALC_RESULT 3 %p\n", tmp);
	*rslt = ft_addinstr(*rslt, tmp, "%", *i - ft_strlen(tmp));
	//free(tmp);
	//printf("\tCALC_RESULT 4 %p\n", tmp);
	return (1);
}

int		fill_result(t_conv **lst, char *format)
{
	static ft_fmt	func;
	char			*rslt;
	int				i;
	t_conv			*tmpc;

	i = 0;
	tmpc = *lst;
	//printf("SEG PRINT 0.0 __%s__\n", format);
	while ((*lst)->next)
	{
		i += lst_final_size(*lst);
		*lst = (*lst)->next;
	}
	*lst = tmpc;
	//printf("SEG PRINT 1.0 __%d__\n", i);
	i += ft_strlen(format);
	//printf("SEG PRINT 1.1 __%d__\n", i);
	rslt = (char *)malloc(sizeof(char) * i);
	i = 0;
	rslt = ft_strcpy(rslt, format);
	rslt = delete_conv_inside(rslt, lst);
	*lst = tmpc;
	initiate_pointer_print(func);
	while (*(rslt + i))
	{
		//printf("SEG PRINT 2.0\n");
		if (*(rslt + i) == '%')
		{
			//printf("SEG PRINT 2.0.0\n");
			if (!calc_result(lst, &rslt, &i, func, tmpc))
				i++;
			*lst = (*lst)->next;
			//printf("SEG PRINT 2.0.1 %s\n", rslt);
		}
		if (*(rslt + i) != '%')
			i++;
		//printf("SEG PRINT 2.1\n");
	}
	//printf("SEG PRINT 3 %p %p\n", *lst, tmpc);
	*lst = tmpc;
	//printf("SEG PRINT 4 %p %p %p\n", *lst, tmpc, rslt);
	return (print_result(lst, rslt));
}
