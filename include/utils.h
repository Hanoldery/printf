/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:09:33 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/09/26 17:20:59 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UTILS_H
# define PRINTF_UTILS_H
/* Verifier si un lien entre define et nom de fichier */
# include <inttypes.h>
# include <wchar.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
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
	struct s_conv	*next;
}					t_conv;


typedef char *(*ft_fmt[123])(t_conv **conv, char *fmt);
void				analyze_conversion(const char *format, va_list args, t_conv **lst);
t_conv				*create_lst_conv();
int					get_lst_conv(const char *format, t_conv **lstconv, va_list args);
int					print_result(t_conv **lst, char *fmt);
void				initiate_pointer(ft_fmt func);
void				initiate_pointer_print(ft_fmt func);
char				*putstr_in_str_if_diff(char *dst, char *a, char c, int i);
int					id_of_char_ifnextnot(char *str, char c, char n);
void				sort_attr(char **attr);

char				*field_fmt(t_conv **conv, char *fmt);
char				*prec_fmt(t_conv **conv, char *fmt);
char				*attr_fmt(t_conv **conv, char *fmt);
char				*length_fmt(t_conv **conv, char *fmt);
char				*conv_fmt(t_conv **conv, char *fmt);
char				*handle_champs(t_conv **conv, char *fmt);


int					handle_null(t_conv **conv, char **fmt, int i);
int					is_null(t_conv **conv);
int					handle_void(t_conv **conv, char **tmp, char **rslt, int i);
char				*handle_hash(t_conv **conv, char *fmt);
char				*handle_zero(t_conv **conv, char *fmt);
char				*handle_minus(t_conv **conv, char *fmt);
char				*handle_space_plus(t_conv **conv, char *fmt);
char				*handle_diu(t_conv **conv, char *fmt);
char				*handle_o(t_conv **conv, char *fmt);
char				*handle_xX(t_conv **conv, char *fmt);
char				*handle_eE(t_conv **conv, char *fmt);
char				*handle_fF(t_conv **conv, char *fmt);
char				*handle_gG(t_conv **conv, char *fmt);
char				*handle_aA(t_conv **conv, char *fmt);
char				*handle_cC(t_conv **conv, char *fmt);
char				*handle_sS(t_conv **conv, char *fmt);
char				*handle_p(t_conv **conv, char *fmt);
char				*handle_n(t_conv **conv, char *fmt);
char				*handle_percent(t_conv **conv, char *fmt);

int					w_size(wchar_t wchar);
char				*wchar_to_str(wchar_t wchar);
char				*wcharstr_to_str(wchar_t *swchar);

#endif
