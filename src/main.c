/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:52:52 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/11/21 16:39:18 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ftprintf.h"
#include <limits.h>

int		main(void)
{
	uintmax_t		i;
	char			c;

	i = 0;
	c = 'o';
	setlocale(LC_ALL, "");
	printf("\nR_%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C", "bonjour", 42, &c, L"暖炉",
			LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	ft_printf("N_%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C", "bonjour", 42, &c, L"暖炉",
			LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	printf("\n\n----\n");
	return (0);
}
