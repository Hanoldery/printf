# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/11 13:08:28 by pgerbaud          #+#    #+#              #
#    Updated: 2017/11/21 12:37:37 by pgerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDE_PATH = include/ libft/

SRCS = 	src/ft_printf.c \
		src/analyze_conversion.c \
		src/analyze_assign.c \
		src/print_result.c \
		src/format.c \
		src/utils.c \
		src/sort_attr.c \
		src/handle_attr.c \
		src/handle_cspn.c \
		src/handle_dec.c \
		src/handle_w.c \
		src/handle_sci.c \
		src/handle_null.c

LIBFT_SRC = putchar \
			putstr \
			putchar_fd \
			putstr_fd \
			strmchr \
			strmchr \
			atoi \
			strchr \
			strsub \
			bzero \
			strlen \
			strfind \
			strdup \
			strcpy \
			strncpy \
			strcat \
			strncat \
			strnew \
			imaxtoa \
			uimaxtoa \
			strjoinfree \
			imaxtoa_base \
			uimaxtoa_base \
			strdelinside
#CFLAGS += -Wall -Wextra -Werror

CFLAGS += $(foreach d, $(INCLUDE_PATH), -I$d)

OBJS = $(patsubst %.c,%.o, $(SRCS))

OBJS += $(foreach ft, $(LIBFT_SRC),libft/ft_$(ft).o)


all : $(NAME)

re : fclean all

src/%.o : src/%.c
	gcc -c $(CFLAGS) $< -o $@

libft/%.o : libft/%.c
	gcc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

clean :
	rm -rf $(OBJS) src/main.o

main : $(NAME) src/main.o
	gcc -o $@ src/main.o -L. -lftprintf

fclean : clean
	rm -rf $(NAME)

.PHONY: all clean fclean re
