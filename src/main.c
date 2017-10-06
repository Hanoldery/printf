/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:52:52 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/10/05 18:00:21 by pgerbaud         ###   ########.fr       */
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
	ft_printf("@moulitest: _%5.x %5.0x_", 0, 0);
	printf("\n@moulitest: _%5.x %5.0x_\n", 0, 0);
	
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
/*	ft_printf("");                               
	ft_printf("\n");                             
	ft_printf("test");                           
	ft_printf("test\n");                         
	ft_printf("1234");                           
	ft_printf("%%");                             
	ft_printf("%5%");                            
	ft_printf("%-5%");                           
	ft_printf("%.0%");                           
	ft_printf("%%", "test");                     
	ft_printf("%   %", "test");                  
	ft_printf("%x", 42);                         
	ft_printf("%X", 42);                         
	ft_printf("%x", 0);                          
	ft_printf("%X", 0);                          
	ft_printf("%x", -42);                        
	ft_printf("%X", -42);                        
	ft_printf("%x", 4294967296);                 
	ft_printf("%X", 4294967296);                 
	ft_printf("%x", 285);                       
	ft_printf("%10x", 42);                       
	ft_printf("%-10x", 42);                      
	ft_printf("%lx", 4294967296);                
	ft_printf("%llX", 4294967296);               
	ft_printf("%hx", 4294967296);                
	ft_printf("%hhX", 4294967296);               
	ft_printf("%jx", 4294967295);                
	ft_printf("%jx", 4294967296);                
	ft_printf("%jx", -4294967296);               
	ft_printf("%jx", -4294967297);               
	ft_printf("%llx", 9223372036854775807);      
	ft_printf("%llx", 9223372036854775808);      
	ft_printf("%010x", 542);                     
	ft_printf("%-15x", 542);                     
	ft_printf("%2x", 542);                       
	ft_printf("%.2x", 5427);                     
	ft_printf("%5.2x", 5427);                    
	ft_printf("%#x", 42);                        
	ft_printf("%#llx", 9223372036854775807);     
	ft_printf("%#x", 0);                         
	ft_printf("%#x", 42);                        
	ft_printf("%#X", 42);                        
	ft_printf("%#8x", 42);                       
	ft_printf("%#08x", 42);                      
	ft_printf("%#-08x", 42);                     
	ft_printf("@moulitest: %#.x %#.0x", 0, 0);   
	ft_printf("@moulitest: %.x %.0x", 0, 0);     
	ft_printf("@moulitest: %5.x %5.0x", 0, 0);   
	ft_printf("%s", "abc");                      
	ft_printf("%s", "this is a string");         
	ft_printf("%s ", "this is a string");        
	ft_printf("%s  ", "this is a string");       
	ft_printf("this is a %s", "string");         
	ft_printf("%s is a string", "this");         
	ft_printf("Line Feed %s", "\n");             
	ft_printf("%10s is a string", "this");       
	ft_printf("%.2s is a string", "this");       
	ft_printf("%5.2s is a string", "this");      
	ft_printf("%10s is a string", "");           
	ft_printf("%.2s is a string", "");           
	ft_printf("%5.2s is a string", "");          
	ft_printf("%-10s is a string", "this");      
	ft_printf("%-.2s is a string", "this");      
	ft_printf("%-5.2s is a string", "this");     
	ft_printf("%-10s is a string", "");          
	ft_printf("%-.2s is a string", "");          
	ft_printf("%-5.2s is a string", "");         
	ft_printf("%s %s", "this", "is");            
	ft_printf("%s %s %s", "this", "is", "a");    
	ft_printf("%s %s %s %s", "this", "is", "a", "multi");
	ft_printf("%s %s %s %s string. gg!", "this", "is", "a", "multi", "string");
	ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
	ft_printf("@moulitest: %s", NULL);           
	ft_printf("%.2c", NULL);                     
	ft_printf("%s %s", NULL, "string");            
	ft_printf("%c", 42);                         
	ft_printf("%5c", 42);                        
	ft_printf("%-5c", 42);                       
	ft_printf("@moulitest: %c", 0);              
	ft_printf("%2c", 0);                         
	ft_printf("null %c and text", 0);            
	ft_printf("% c", 0);                         
	ft_printf("%o", 40);                         
	ft_printf("%5o", 41);                        
	ft_printf("%05o", 42);                       
	ft_printf("%-5o", 2500);                     
	ft_printf("%#6o", 2500);                     
	ft_printf("%-#6o", 2500);                    
	ft_printf("%-05o", 2500);                    
	ft_printf("%-5.10o", 2500);                  
	ft_printf("%-10.5o", 2500);                  
	ft_printf("@moulitest: %o", 0);              
	ft_printf("@moulitest: %.o %.0o", 0, 0);     
	ft_printf("@moulitest: %5.o %5.0o", 0, 0);   
	ft_printf("@moulitest: %#.o %#.0o", 0, 0);   
	ft_printf("@moulitest: %.10o", 42);          
	ft_printf("%d", 1);                          
	ft_printf("the %d", 1);                      
	ft_printf("%d is one", 1);                   
	ft_printf("%d", -1);                         
	ft_printf("%d", 4242);                       
	ft_printf("%d", -4242);                      
	ft_printf("%d", 2147483647);                 
	ft_printf("%d", 2147483648);                 
	int index;
	unsigned int uindex;
	i = -2147483648;
	ft_printf("%d", i);              
	i--;
	ft_printf("%d", i);              
	ft_printf("% d", 42);                        
	ft_printf("% d", -42);                       
	ft_printf("%+d", 42);                        
	ft_printf("%+d", -42);                       
	ft_printf("%+d", 0);                         
	ft_printf("% +d", 42);                       
	ft_printf("% +d", -42);                      
	ft_printf("%+ d", 42);                       
	ft_printf("%+ d", -42);                      
	ft_printf("%  +d", 42);                      
	ft_printf("%  +d", -42);                     
	ft_printf("%+  d", 42);                      
	ft_printf("%+  d", -42);                     
	ft_printf("% ++d", 42);                      
	ft_printf("% ++d", -42);                     
	ft_printf("%++ d", 42);                      
	ft_printf("%++ d", -42);                     
	ft_printf("%0d", -42);                       
	ft_printf("%00d", -42);                      
	ft_printf("%5d", 42);                        
	ft_printf("%05d", 42);                       
	ft_printf("%0+5d", 42);                      
	ft_printf("%5d", -42);                       
	ft_printf("%05d", -42);                      
	ft_printf("%0+5d", -42);                     
	ft_printf("%-5d", 42);                       
	ft_printf("%-05d", 42);                      
	ft_printf("%-5d", -42);                      
	ft_printf("%-05d", -42);                     
	ft_printf("%hd", 32767);                     
	i = -32768;
	ft_printf("%hd", i);                  
	ft_printf("%hd", 32768);
	i--;
	ft_printf("%hd", i);                  
	ft_printf("%hhd", 127);                      
	ft_printf("%hhd", 128);                      
	ft_printf("%hhd", -128);                     
	ft_printf("%hhd", -129);                     
	ft_printf("%ld", 2147483647);                
	uindex = 2147483648;             
	uindex = -uindex;
	ft_printf("%ld", uindex);             
	ft_printf("%ld", 2147483648);
	uindex--;
	ft_printf("%ld", uindex);             
	ft_printf("%lld 1", 9223372036854775807);      
	ft_printf("%lld 2", -9223372036854775808);     
	ft_printf("%jd 3", 9223372036854775807);       
	unsigned long ulong;
	ulong = 9223372036854775808;    
	ulong = -ulong;
	ft_printf("%jd", ulong);    
	ft_printf("%zd", 4294967295);                
	ft_printf("%zd", 4294967296);                
	ft_printf("%zd", 0);                      
	i = -1;
	ft_printf("%zd", i);                      
	ft_printf("%d", 1);                          
	ft_printf("%d %d", 1, -2);                   
	ft_printf("%d %d %d", 1, -2, 33);            
	ft_printf("%d %d %d %d", 1, -2, 33, 42);     
	ft_printf("%d %d %d %d gg!", 1, -2, 33, 42, 0);
	ft_printf("%4.15d", 42);                     
	ft_printf("%.2d", 4242);                     
	ft_printf("%.10d", 4242);                    
	ft_printf("%10.5d", 4242);                   
	ft_printf("%-10.5d", 4242);                  
	ft_printf("% 10.5d", 4242);                  
	ft_printf("%+10.5d", 4242);                  
	ft_printf("%-+10.5d", 4242);                 
	ft_printf("%03.2d", 0);                      
	ft_printf("%03.2d", 1);                      
	ft_printf("%03.2d", -1);                     
	ft_printf("@moulitest: %.10d", -42);         
	ft_printf("@moulitest: %.d %.0d", 42, 43);   
	ft_printf("@moulitest: %.d %.0d", 0, 0);     
	ft_printf("@moulitest: %5.d %5.0d", 0, 0);   
	ft_printf("%u", "0");                        
	ft_printf("%u", "1");                        
	ft_printf("%u", "-1");                       
	ft_printf("%u", "4294967295");               
	ft_printf("%u", "4294967296");               
	ft_printf("%5u", "4294967295");              
	ft_printf("%15u", "4294967295");             
	ft_printf("%-15u", "4294967295");            
	ft_printf("%015u", "4294967295");            
	ft_printf("% u", "4294967295");              
	ft_printf("%+u", "4294967295");              
	ft_printf("%lu", "4294967295");              
	ft_printf("%lu", "4294967296");              
	ft_printf("%lu", "-42");                     
	ft_printf("%llu", "4999999999");             
	ft_printf("%ju", "4999999999");              
	ft_printf("%ju", "4294967296");              
	ft_printf("%U", "4294967295");               
	ft_printf("%hU", "4294967296");              
	ft_printf("%U", "4294967296");               
	ft_printf("@moulitest: %.5u", "42");*/

	return (0);
}
