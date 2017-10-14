


#include "utils.h"

void		sort_attr(char **attr)
{
	int		i;
	int		j;
	char	tmp;

	tmp = 0;
	i = 0;
	j = 0;
	while ((*attr)[i])
	{
		tmp = (*attr)[i];
		j = i + 1;
		while ((*attr)[j])
			if (tmp == (*attr)[j++])
				ft_strdelinside(attr, j - 2, j);
		i++;
	}
	i = 0;
	if (ft_strchr(*attr, ' ') && ft_strchr(*attr, '+'))
	{
		i = ft_strfind(*attr, ' ');
		ft_strdelinside(attr, i - 1, i + 1);
		i++;
	}
}
