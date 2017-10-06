/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:17:54 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/05 19:11:05 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		assign_args(t_conv **lstconv, va_list args)
{
	if (ft_strchr("diouxX", (*lstconv)->conv))
	{
		if ((*lstconv)->modif[0] == 'h')
			(*lstconv)->data[0] = va_arg(args, int);
		else if ((*lstconv)->modif[0] == 'l')
			(*lstconv)->data[0] = (ft_strchr("di", (*lstconv)->conv)) ?
				va_arg(args, signed long) : va_arg(args, unsigned long);
		else if ((*lstconv)->modif[0] == 'l' && (*lstconv)->modif[1] == 'l')
			(*lstconv)->data[0] = (ft_strchr("di", (*lstconv)->conv)) ?
				va_arg(args, long long) : va_arg(args, unsigned long long);
		else if ((*lstconv)->modif[0] == 'j')
			(ft_strchr("di", (*lstconv)->conv)) ?
				(*lstconv)->data[0] = va_arg(args, intmax_t)
				: ((*lstconv)->data[0] = va_arg(args, intmax_t));
		else
			(*lstconv)->data[0] = va_arg(args, int);
	}
	if (ft_strchr("aAeEfFgG", (*lstconv)->conv) && (*lstconv)->modif[0] == 'L')
		(*lstconv)->data[0] = va_arg(args, long double);
	else if (ft_strchr("aAeEfFgG", (*lstconv)->conv))
		(*lstconv)->data[0] = va_arg(args, double);
	if ((*lstconv)->conv == 'n')
	{
		if ((*lstconv)->modif[0] == 'h')
			(*lstconv)->data = ((*lstconv)->modif[1] == 'h') ?
				(intmax_t *)va_arg(args, signed char *)
				: (intmax_t *)va_arg(args, int *);
		else if ((*lstconv)->modif[0] == 'l')
			(*lstconv)->data = ((*lstconv)->modif[1] == 'l') ?
				(intmax_t *)va_arg(args, long long int *) :
				(intmax_t *)va_arg(args, long int *);
	}
	if (ft_strchr("cs", (*lstconv)->conv))
	{
		if ((*lstconv)->conv == 'c')
			((*lstconv)->modif[0] == 'l') ?
				((*lstconv)->sdata[0] = va_arg(args, wint_t)) :
				((*lstconv)->sdata[0] = va_arg(args, int));
		else if ((*lstconv)->conv == 's')
		{
			((*lstconv)->modif[0] == 'l') ?
				((*lstconv)->sdata = (wint_t *)va_arg(args, wchar_t *))
				: ((*lstconv)->sdata = (wint_t *)va_arg(args, char *));
			if ((*lstconv)->sdata == (int *)0xa)
				(*lstconv)->sdata = NULL;
		}
	}

}

void		assign_nexts(t_conv **lst, va_list args, int j, int *i)
{
	va_list cp;

//	printf("ASSIGN 0.0\n");
	if ((*lst)->champs == 0)
		*i = ((*lst)->champs = va_arg(cp, unsigned int)) ? *++i: *i;
//	printf("ASSIGN 1.0\n");
	if (!(*lst)->prec_changed && (*lst)->precision == 0)
		*i = ((*lst)->precision = va_arg(cp, unsigned int)) ? *++i: *i;
//	printf("ASSIGN 2.0\n");
	if ((*lst)->champs < 0)
	{
//	printf("ASSIGN 3.0\n");
		va_copy(cp, args);
		while (j++ < *i)
			va_arg(cp, void *);
		(*lst)->champs = va_arg(cp, int);
		va_end(cp);
	}
//	printf("ASSIGN 4.0\n");
	j = 0;
	if ((*lst)->precision < 0)
	{
//	printf("ASSIGN 5.0\n");
		va_copy(cp, args);
		while (j++ < *i)
			va_arg(cp, void *);
		(*lst)->precision = va_arg(cp, int);
		va_end(cp);
	}
//	printf("ASSIGN 6.0\n");
}

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
		//printf("\t%d.0\n", i);
		if (lstmp->conv == '%')
		{
			lstmp = lstmp->next;
			continue;
		}
		va_copy(cp, args);
		//printf("\t%d.1\n", i);
		assign_nexts(&lstmp, args, 0, &i);
		if (lstmp->pos != 0)
		{
			//printf("\t%d.2 pos%d\n", i, lstmp->pos);
			i--;
			while (icp++ < lstmp->pos - 1)
			{
				//printf("\t%d.3.%d\n", i, icp);
				va_arg(cp, void*);
			}
		}
		else
		{
			//printf("\t%d.4\n", i);
			while (icp++ < i)
			{
				//printf("\t%d.5\n", i);
				va_arg(cp, void*);
			}
		}
		assign_args(&lstmp, cp);
		va_end(cp);
		i++;
		icp = 0;
//		printf("\n\t__LAST %s__ \n\tDATA : %jd\n\tUDATA %ju\n\tSDATA : _%s_\n\tpos %d\t\tattr %s\n\tchamps %d\tprecision %d\n\tmodif %s\t\tconv %c\n\n", format, lstmp->data[0], lstmp->udata, (wint_t *)lstmp->sdata, lstmp->pos, lstmp->attr, lstmp->champs, lstmp->precision, lstmp->modif, lstmp->conv);
		lstmp = lstmp->next;
	}
	return 1;
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
				return 1;
		}
		else
			tmp++;
	}
	return 1;
}

void		analyze_conversion(const char *format, va_list args, t_conv **lst)
{
	t_conv	*lstmp;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(format);
	lstmp = *lst;
//	printf("ANALYZE 0.0\n");
	while (*tmp)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		if (!(tmp = ft_strchr(tmp, '%')))
			break;
		/*if (!(ft_strmchr(tmp, "diuxXeEfFaAgGcCsSpn")))
			 MAYBE Peut-etre rajouter un '\0' a la fin
			return (NULL);*/
//		printf("ANALYZE 1.0 %d\n", (*lst)->precision);
		analyze_conversion_dtls(tmp, lst, args);
//		printf("ANALYZE 2.0 \t%s \t\t%s \t\t%d\n", format, tmp, i);
	/*		printf("NULL CHAIN\n");  TODO return (NULL); a remplacer 
		else
			printf("\nCHAIN\n\n");*/
//		printf("tmp : %s \tft_strmchr : %s\n", tmp, ft_strmchr(tmp, "diuxXeEfFaAgGcCsSpn%"));
		tmp = ft_strmchr(tmp, "diuxXeEfFaAgGcCsSpn%");
//		printf("\n\t__FIRST %s__ \n\tDATA : %jd\n\tUDATA %ju\n\tSDATA : _%s_\n\tpos %d\t\tattr %s\n\tchamps %d\tprecision %d\n\tmodif %s\t\tconv %c\n\n", format, (*lst)->data[0], (*lst)->udata, (wint_t *)(*lst)->sdata, (*lst)->pos, (*lst)->attr, (*lst)->champs, (*lst)->precision, (*lst)->modif, (*lst)->conv);
		(*lst)->next = create_lst_conv();
		i++;
		tmp++;
	}
//	printf("ANALYZE 2.5\n");
	*lst = lstmp;
	get_lst_conv(format, lst, args);
}
