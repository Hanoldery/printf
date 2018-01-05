# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/11 13:08:28 by pgerbaud          #+#    #+#              #
#    Updated: 2018/01/05 18:19:58 by pgerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDE_PATH = include/ libft/includes/

SRCS = 	src/ft_printf.c \
		src/analyze_conversion.c \
		src/analyze_assign.c \
		src/print_result.c \
		src/format.c \
		src/utils.c \
		src/lst_utils.c \
		src/sort_attr.c \
		src/handle_attr.c \
		src/handle_cspn.c \
		src/handle_dec.c \
		src/handle_w.c \
		src/handle_sci.c \
		src/handle_null.c

LIBFT_SRC = atoi \
			bzero \
			imaxtoa \
			imaxtoa_base \
			iprintsize \
			memcpy \
			putchar \
			putchar_fd \
			putstr \
			putstr_fd \
			straddinstr \
			strcat \
			strchr \
			strcpy \
			strdel \
			strdelinside \
			strdup \
			strfill \
			strfind \
			strjoinfree \
			strlen \
			strmchr \
			strmintchr \
			strncat \
			strncmp \
			strncpy \
			strnew \
			strsub \
			uimaxtoa \
			uimaxtoa_base \
			uiprintsize

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
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) libft/libft.a

.PHONY: all clean fclean re
