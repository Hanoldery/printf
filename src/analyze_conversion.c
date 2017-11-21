/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:17:54 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/11/21 12:36:19 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** JUST IN CASE I WOULD LIKE TO MAKE THE BONUS
**	if (lstmp->pos != 0 && i--)
**		while (icp++ < lstmp->pos - 1)
**			va_arg(cp, void*);
**	else
*/

int			get_lst_conv(const char *format, t_conv **lstconv, va_list args)
{
	t_conv	*lstmp;
	int		i;
	int		icp;
	va_list	cp;

	i = 0;
	icp = 0;
	lstmp = *lstconv;
	while (lstmp)
	{
		if (lstmp->conv == '%' && (lstmp = lstmp->next))
			continue;
		va_copy(cp, args);
		assign_next(&lstmp, args, 0, &i);
		while (icp++ < i)
			va_arg(cp, void*);
		assign_arg(&lstmp, cp);
		va_end(cp);
		i++;
		icp = 0;
		lstmp = lstmp->next;
	}
	return (1);
}

int			analyze_conversion_dtls(const char *s, t_conv **lstconv, va_list a)
{
	int				i;
	char			*tmp;
	static ft_fmt	func;

	initiate_pointer(func);
	tmp = ft_strdup(s);
	i = 0;
	tmp++;
	while (*tmp)
	{
		if (func[*tmp])
		{
			tmp = func[*tmp](lstconv, tmp);
			if (!tmp)
				return (1);
		}
		else
			tmp++;
	}
	return (1);
}

void		analyze_conversion(const char *format, va_list args, t_conv **lst)
{
	t_conv	*lstmp;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(format);
	lstmp = *lst;
	while (*tmp)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		if (!(tmp = ft_strchr(tmp, '%')))
			break ;
		analyze_conversion_dtls(tmp, lst, args);
		tmp = ft_strmchr(tmp, "diuxXeEfFaAgGcCsSpn%");
		(*lst)->next = create_lst_conv();
		i++;
		if (*tmp == '%' && *(tmp + 1) == '%')
			tmp++;
		tmp++;
	}
	*lst = lstmp;
	get_lst_conv(format, lst, args);
}
