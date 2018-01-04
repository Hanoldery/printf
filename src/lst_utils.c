/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:03:38 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/04 20:14:27 by pgerbaud         ###   ########.fr       */
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
	nlst->data = (intmax_t *)malloc(sizeof(intmax_t) * 2);
	nlst->data[0] = 0;
	nlst->sdata = (wint_t *)malloc(sizeof(wint_t) * 2);
	nlst->sdata[0] = 0;
	nlst->udata = 0;
	nlst->champs = 0;
	nlst->precision = 0;
	nlst->prec_changed = 0;
	nlst->champs_changed = 0;
	nlst->valid = 1;
	nlst->conv = '\0';
	nlst->modif = ft_strnew(3);
	return (nlst);
}

int			lst_final_size(t_conv *lst)
{
	int		i;

	i = 0;
	//printf("\t\t-- LST_ULTILS %c --\n", lst->conv);
	if (ft_strchr("dDi", lst->conv))
	{
		//printf("\t\t LST_ULTILS  dDii %d\n", i);
		if (lst->data && *(lst->data))
			i = ft_iprintsize(*(lst->data)) + 1;
		//printf("\t\t LST_ULTILS  dDii %d\n", i);
	}
	else if (ft_strchr("oOuUxXpP", lst->conv))
	{
		//printf("\t\t LST_ULTILS  oOuUxXpP %d\n", i);
		if (lst->udata)
			i = ft_uiprintsize(lst->udata) + 1;
		//printf("\t\t LST_ULTILS  oOuUxXpP %d\n", i);
	}
	else if (ft_strchr("csCS", lst->conv))
	{
		//printf("\t\t LST_ULTILS cs %p\n", lst->sdata);
		if ((long)lst->sdata)
			i = (int)ft_strlen((char *)lst->sdata);
		if ((long)lst->sdata)
			if (ft_strchr(lst->modif, 'l') || ft_strchr("CS", lst->conv))
				i = wchar_size(lst->sdata);
	}
	i += 6;
	//printf("\t\t LST_FINAL_SIZE i%d chps%d prec%d\n", i, lst->champs, lst->precision);
	//printf("\t\t LST_FINAL_SIZE i%d chps%d prec%d data%d udata%d sdata%s\n", i, lst->champs, lst->precision, ft_iprintsize(lst->data), ft_uiprintsize(lst->udata), (int)ft_strlen((char *)lst->sdata));
	i += lst->champs;
	i += lst->precision;
	return (i);
}

int			lst_size(t_conv *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
