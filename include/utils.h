/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:09:33 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/05 14:26:04 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <inttypes.h>
# include <wchar.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <locale.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct		s_conv
{
	intmax_t		*data;
	uintmax_t		udata;
	wint_t			*sdata;
	int				pos;
	char			*attr;
	int				champs;
	int				precision;
	int				prec_changed;
	int				champs_changed;
	char			*modif;
	char			conv;
	int				valid;
	struct s_conv	*next;
}					t_conv;

typedef char *(*t_fmt[123])(t_conv **conv, char *fmt);
int					analyze_conversion(const char *format, va_list args,
		t_conv **lst);
t_conv				*create_lst_conv();
int					lst_final_size(t_conv *lst);
int					lst_sum_size(t_conv *lst, char *format);
int					get_lst_conv(t_conv **lstconv, va_list args);

void				assign_arg(t_conv **conv, va_list args);
void				assign_arg_unsigned(t_conv **conv, va_list args);
void				assign_arg_signed(t_conv **conv, va_list args);
void				assign_arg_special(t_conv **conv, va_list args);
void				assign_next(t_conv **conv, va_list args, int j, int *i);

int					fill_result(t_conv **lst, char *fmt);
void				initiate_pointer(t_fmt func);
void				initiate_pointer_print(t_fmt func);
int					id_of_char_ifnextnot(char *str, char c, char n);
void				sort_attr(t_conv **conv, char **attr);
char				*ft_addinstr(char *dst, char *a, char *c, int i);
char				*ft_addinstrtest(char *dst, char *a, char *c, int i,
		t_conv *lst);

char				*field_fmt(t_conv **conv, char *fmt);
char				*prec_fmt(t_conv **conv, char *fmt);
char				*attr_fmt(t_conv **conv, char *fmt);
char				*length_fmt(t_conv **conv, char *fmt);
char				*conv_fmt(t_conv **conv, char *fmt);
char				*handle_champs(t_conv **conv, char *fmt);

int					handle_null(t_conv **conv, char **fmt, int i);
void				handle_invalid_conv(t_conv **c, char **r, int *b, int *e);
int					is_null(t_conv **conv);
int					handle_void(t_conv **conv, char **tmp, char **rslt, int i);
char				*handle_hash(t_conv **conv, char *fmt);
char				*handle_space_plus(t_conv **conv, char *fmt);
char				*handle_di(t_conv **conv, char *fmt);
char				*handle_ou(t_conv **conv, char *fmt);
char				*handle_x(t_conv **conv, char *fmt);
char				*handle_e(t_conv **conv, char *fmt);
char				*handle_f(t_conv **conv, char *fmt);
char				*handle_g(t_conv **conv, char *fmt);
char				*handle_a(t_conv **conv, char *fmt);
char				*handle_c(t_conv **conv, char *fmt);
char				*handle_s(t_conv **conv, char *fmt);
char				*handle_n(t_conv **conv, char *fmt);
char				*handle_percent(t_conv **conv, char *fmt);

int					w_size(wchar_t wchar);
int					wchar_size(wchar_t *swchar);
char				*wchar_to_str(wchar_t wchar);
char				*wcharstr_to_str(wchar_t *swchar, t_conv **conv);

#endif
