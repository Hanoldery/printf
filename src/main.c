/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:52:52 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/09/26 17:38:44 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ftprintf.h"

int		main(void)
{
	char	*str;
	int		i;
	double	d;

	i = 0;
	d = 21.21;
	ft_printf("ouais%.12%i");
	//ft_printf("%d %*.*d %6$s", 5, 10, 15, 20, 25, "ypo");

	/*
	ft_printf("ouais c'est cool %*2$.*2$d", 1, 2);
	ft_printf("ouais c'est cool %#+-d %d", 1, 2, 3);

	printf("|%10.5d|\n", -12);
	printf("|%10d|\n", -12);
	printf("|%010d|\n", -12); 
	printf("|%-10.5d|\n", -12);

	
	   ft_printf("DETAIL DE CONVERSION\n");
	   ft_printf("#o   \t\t_%#o \t0\n", 0);
	   ft_printf("#o   \t\t_%#o \t012\n", 10);
	   ft_printf("#.5o   \t\t_%#.5o \t00012\n", 10);
	   ft_printf("#.0o   \t\t_%#.0o \t012\n", 10);
	   ft_printf("0#x   \t\t_%#x \t0\n", 0);
	   ft_printf("#x   \t\t_%#x \t0xc\n", 12);
	   ft_printf("#e   \t\t_%#e \t2.121000e+01\n", d);
	   ft_printf("#.0e   \t\t_%#.0e \t2.e+01\n", d);
	   ft_printf(".0e   \t\t_%.0e \t\t2e+01\n", d);
	   ft_printf("#f   \t\t_%#f \t21.210000\n", d);
	   ft_printf("#a   \t\t_%#a \t0x1.5p+4\n", 21.0);
	   ft_printf("#g   \t\t_%#g \t21.2100\n", d);

	   ft_printf("\nREMPLIR AVEC 0\n");
	   ft_printf("05d   \t\t_%05d \t00010\n", 10);
	   ft_printf("00d   \t\t_%00d \t10\n", 10);
	   ft_printf("01.3d   \t_%01.3d \t010\n", 10);

	   ft_printf("\n - ALIGNE A GAUCHE\n");
	   ft_printf("4d   \t_%4d \t  10\n", 10);
	   ft_printf("-4d   \t_%-4d \t10  \n", 10);

	   ft_printf("\n+ IMPRIME TOUJOURS SIGNE\n");
	   ft_printf("+f   \t\t%+f \t\n", 10.);

	   ft_printf("\nLARGEUR DE CHAMPS\n");
	   ft_printf("1c   \t_%1c \t010\n", 'Y');

	   ft_printf("\nPRECISION\n");
	   ft_printf("1.3d   \t_%1.3d \t010\n", 10);
	   ft_printf("-.12d \t_%-.12d_ \t010\n", 10);
	   ft_printf(".12d \t_%.12d_ \t010\n", 10);
	   ft_printf("-.6f \t_%-.6f \t010\n", 10.);
	   ft_printf("-12.6f \t_%-12.6f \t010\n", 10.);
	   ft_printf("12.6f \t_%12.6f \t010\n", 10.);
	   ft_printf("4.3s  \t_%4.3s \t010\n", "YoMan");
	   ft_printf("4.s  \t_%4.s \t010\n", "YoMan");
	   ft_printf("0.s   \t_%.s \t010\n", "YoMan");
	   ft_printf("0.d   \t_%0.d \t010\n", 10);
	   ft_printf(".3f   \t_%.3f \t010\n", 10.);

	   ft_printf("\nMODIFICATEUR DE LONGUEUR\n");

	   ft_printf("\nINDICATEUR DE CONVERSION\n");
	   ft_printf("d   \t_%lld \t010\n", 99999999999999999);
	   ft_printf("o   \t_%o \t010\n", -2);
	   ft_printf("u   \t_%u \t010\n", -2);

	   ft_printf("\nPLUS DE FORMAT\n");
	   ft_printf("Placement %1$d bad, %d\n", 2, 5);*/

	return (0);
}
