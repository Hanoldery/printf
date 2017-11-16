

#include "utils.h"

void			handle_invalid_conv(t_conv **conv, char **rslt, int *b, int *e)
{
	int		i;
	int		len;
	int		minus;

	i = 0;
	minus = (ft_strchr((*conv)->attr, '-')) ? *e - *b + 1 : 0;
	len = ft_strlen(*rslt);
	(*conv)->valid = 0;
	(*conv)->champs--;
	if ((*conv)->champs_changed)
	{
		while (*(*rslt + i) && *(*rslt + i) != '%')
			i++;
		while (ft_strlen(*rslt) - len < (*conv)->champs)
			*rslt = (ft_strchr((*conv)->attr, '0')) ? 
				ft_addinstr(*rslt, "0", 0, minus + i++) :
				ft_addinstr(*rslt, " ", 0, minus + i++);
	}
	if (!minus && (*conv)->champs_changed)
	{
		*e += (*conv)->champs;
		*b += (*conv)->champs - 1;
	}
	else
		*b -= 1;
}

int			handle_void(t_conv **conv, char **tmp, char **rslt, int i)
{
	if (!ft_strlen(*tmp))
	{
		ft_strdelinside(rslt, i - 1, i + 1);
	}
	/*else if (!(*conv)->conv)
	{
		printf("\t\tFAKE CONV %s\n", *rslt);
		ft_strdelinside(rslt, i - 2, i);
		printf("\t\tFAKE CONV %s\n", *rslt);
	}*/
	else if (is_null(conv) && ft_strchr("oOxX", (*conv)->conv)
			&& (*conv)->prec_changed && 
			!(ft_strchr((*conv)->attr, '#') && ft_strchr("oO", (*conv)->conv)))
	{
		if (!(*conv)->champs_changed)
		{
			ft_strdelinside(rslt, i - 2, i );
			return (1);
		}
		i = ft_strfind(*tmp, '0');
		ft_strdelinside(tmp, i - 1, i + 1);
		*tmp = ft_addinstr(*tmp, " ", "0", i);
		return (0);
	}
	else
		return (0);
	return (1);
}

int			is_null(t_conv **conv)
{
	if (!(*conv)->data || !(*conv)->sdata)
		return (1);
	if (!*(*conv)->data && !*(*conv)->sdata && !(*conv)->udata
			&& (*conv)->conv != '%' 
			&& !(ft_strchr("s", (*conv)->conv) && *(*conv)->modif == 'l'))
		return (1);
	return (0);
}

int			handle_null(t_conv **conv, char **tmp, int j)
{
	int		i;

	i = 0;
	if (is_null(conv))
	{
	//	printf("\t\tIS_NULL %c %d %d\n", (*conv)->conv, !(*conv)->prec_changed, (*conv)->precision != 0);
		if (ft_strchr("oOxX", (*conv)->conv) || ft_strchr((*conv)->attr, '#')
				|| ((*conv)->conv == 'd' && (!(*conv)->prec_changed
					|| (*conv)->precision != 0))
				|| ((*conv)->conv == 'u' && !(*conv)->prec_changed))
			return (0);
		if (ft_strchr("sS", (*conv)->conv) && (*conv)->prec_changed == 0)
		{
			*tmp = ft_strdup("(null)");
			return (1);
		}
		if ((*conv)->conv == 'c')
			i = ((*conv)->champs_changed) ? i + (*conv)->champs + 1 : i + 1;
		(*conv)->pos = ((*conv)->champs_changed) ? j + (*conv)->champs - 1 : j;
//		TODO USEFULL UNDER THAT ?
		while (*(*tmp + i))
			*(*tmp + i++) = '\0';
		return (1);
	}
	return (0);
}
