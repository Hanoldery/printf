/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:17:54 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/12/07 10:40:43 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** JUST IN CASE I WOULD LIKE TO MAKE THE BONUS
**	if (lstmp->pos != 0 && i--)
**		while (icp++ < lstmp->pos - 1)
**			va_arg(cp, void*);
**	else
**
**
**	t_conv	*lstmp;
**	int		i;
**	int		icp;
**	va_list	cp;
**
**	i = 0;
**	icp = 0;
**	lstmp = *lstconv;
**	while (*lstconv)
**	{
**		if ((*lstconv)->conv == '%' && ((*lstconv) = (*lstconv)->next))
**			continue;
**		//va_copy(cp, args);
**		//assign_next(lstconv, args, 0, &i);
**		//while (icp++ < i)
**		//	va_arg(cp, void*);
**		assign_arg(lstconv, args);
**		i++;
**		icp = 0;
**		*lstconv = (*lstconv)->next;
**	}
**	*lstconv = lstmp;
**	return (1);
*/

int			get_lst_conv(const char *format, t_conv **lstconv, va_list args)
{
	t_conv	*lstmp;

	lstmp = *lstconv;
	while (*lstconv)
	{
		if ((*lstconv)->conv == '%' && ((*lstconv) = (*lstconv)->next))
			continue;
		assign_arg(lstconv, args);
		*lstconv = (*lstconv)->next;
	}
	*lstconv = lstmp;
	return (1);
}

int			analyze_conversion_dtls(char *s, t_conv **lstconv, va_list a)
{
	char			*tmp;
	static ft_fmt	func;

	//printf("ANALYZE_DTLS 0 _%s_\n", s);
	initiate_pointer(func);
	tmp = (char *)s;
	//printf("ANALYZE_DTLS 1 _%s_%s_\n", s, tmp);
	tmp++;
	while (*tmp)
	{
		if (func[*tmp])
		{
			tmp = func[*tmp](lstconv, tmp);
			if (tmp == (char *)-1)
				return (0);
			if (!tmp)
				break ;
		}
		else
			tmp++;
	}
	//printf("ANALYZE_DTLS _%s_\n", tmp);
	return (1);
}

int			analyze_conversion(const char *format, va_list args, t_conv **lst)
{
	t_conv	*lstmp;
	char	*tmp;
	char	*del;

	//printf("ANALYZE CONV 0 fmt_%s_\n", format);
	tmp = ft_strdup(format);
	del = tmp;
	lstmp = *lst;
	//printf("ANALYZE CONV 1 tmp_%s_\n", tmp);
	while (*tmp)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		//printf("ANALYZE CONV 1.0 tmp_%s_\n", tmp);
		if (!(tmp = ft_strchr(tmp, '%')))
			break ;
		//printf("ANALYZE CONV 1.1 tmp_%s_\n", tmp);
		if (!analyze_conversion_dtls(tmp, lst, args))
			return (0);
		tmp = ft_strmchr(tmp, "diuxXeEfFaAgGcCsSpn%");
		(*lst)->next = create_lst_conv(); /*TENTER DE CHANGER LA FACON DE CREER UNE STRUCT */
		((*lst)->next)->pos = (*lst)->pos + 1;
		if (*tmp == '%' && *(tmp + 1) == '%')
			tmp++;
		tmp++;
	}
	free(del);
	*lst = lstmp;
	get_lst_conv(format, lst, args);
			t_conv *ltmp;
			ltmp = lstmp;
			while (ltmp)
			{
				//printf("--- PRINT UNDERZERO %d\n%p %p\n", ltmp->pos, ltmp->sdata, ltmp->data);
				ltmp = ltmp->next;
			}
	return (1);
}
