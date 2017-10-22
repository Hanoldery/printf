

#include "utils.h"

int			handle_void(t_conv **conv, char **tmp, char **rslt, int i)
{
	if (!ft_strlen(*tmp) && (*conv)->conv == 'c')
	{
		(*conv)->pos = i;
//		printf("printf 0\n");
//		*(*rslt + i) = 0;
	}
	else if (!ft_strlen(*tmp))
	{
//		printf("DEL from _%s_ to _%s_ in _%s_\n", *rslt + i - 1, *rslt + i + 1, *rslt);
		ft_strdelinside(rslt, i - 1, i + 1);
	}
	else
		return (0);
	return (1);
}

int			is_null(t_conv **conv)
{
	if (!(*conv)->data || !(*conv)->sdata)
		return (1);
	if (!*(*conv)->data && !*(*conv)->sdata && !(*conv)->udata && (*conv)->conv != '%')
		return (1);
	return (0);
}

int			handle_null(t_conv **conv, char **tmp, int j)
{
	int		i;

	i = 0;
	if (is_null(conv))
	{
		if ((*conv)->conv == 'o' || ft_strchr((*conv)->attr, '#'))
			return (0);
		if (ft_strchr("sS", (*conv)->conv))
		{
			*tmp = ft_strdup("(null)");
			return (1);
		}
		if ((*conv)->conv == 'c')
			i = ((*conv)->champs_changed) ? i + (*conv)->champs + 1 : i + 1;
		(*conv)->pos = j;
//		if ((*conv)->prec_changed && (*conv)->precision == 0)
			while (*(*tmp + i))
				*(*tmp + i++) = '\0';
		return (1);
	}
	return (0);
}
