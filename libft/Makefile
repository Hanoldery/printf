# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pierre <Pierre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 14:30:42 by pgerbaud          #+#    #+#              #
#    Updated: 2018/01/05 18:11:29 by pgerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CFLAGS=-Wall -Wextra -Werror

SRC = 	ft_atoi.c \
		ft_bzero.c \
		ft_imaxtoa.c \
		ft_imaxtoa_base.c \
		ft_iprintsize.c \
		ft_memcpy.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_straddinstr.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdelinside.c \
		ft_strdup.c \
		ft_strfill.c \
		ft_strfind.c \
		ft_strjoinfree.c \
		ft_strlen.c \
		ft_strmchr.c \
		ft_strmintchr.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strsub.c \
		ft_uimaxtoa.c \
		ft_uimaxtoa_base.c \
		ft_uiprintsize.c

INC=./includes

OBJ=${SRC:.c=.o}

all : $(NAME)

$(NAME) :
	gcc -c $(SRC) -I$(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
