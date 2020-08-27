/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:40:42 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 18:04:12 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include <math.h>
# include <ctype.h>
# define ALLSYMBOLS		"cCsSpdDiouUxXfFyb#-+% .*0123456789hLljzk"

typedef struct		s_tab
{
	char			*format;
	int				len;
	int				tmp_len;
	int				i;
	int				width;
	int				negative;
	int				p;
	unsigned char	hash;
	int				precision;
	unsigned char	minus;
	char			zero;
	unsigned char	plus;
	char			space;
	int				n;
	unsigned char	type;
	char			*tmp;
	int				l;
	int				h;
	int				ll;
	int				hh;
	int				z;
	int				j;
	int				l_b;
	char			size_flag[2];
	char			format_flag[5];
	int				arg_len;
	char			*ap2;
}					t_tab;

int					ft_printf(const char *format, ...);
void				check_width(char *tmp, t_tab *tab);
void				parse(t_tab *tab, va_list arg);
void				init(t_tab *tab);
int					check_percent(char *format, t_tab *tab);
void				print_arg(char *format, t_tab *tab, va_list arg);
void				flag_pars(const char *format, t_tab *tab);
void				size_parse(char *format, t_tab *tab);
void				check_type(t_tab *tab, va_list arg);
void				form_parser(t_tab *tab, va_list arg);
void				print_str(va_list arg, t_tab *tab);
void				print_x(t_tab *tab, va_list arg);
void				print_p(t_tab *tab, va_list arg);
void				init_tab(t_tab *tab);
void				print_int(t_tab *tab, int ap);
intmax_t			get_int(t_tab *tab, va_list arg);
void				convert_d(t_tab *tab, intmax_t n, int num_width, int left);
char				get_sign(t_tab *tab, int is_neg);
void				ft_putnbrmax(intmax_t n);
void				ft_putnbrumax(uintmax_t n);
void				convert_u(t_tab *tab, uintmax_t num, int num_width,
					int left);
uintmax_t			get_u(t_tab *tab, va_list arg);
void				convert_o(t_tab *tab, uintmax_t num, char *str, int left);
void				convert_p(t_tab *tab, char *str, int left);
char				*ft_strndup(const char *s1, size_t n);
void				print_o(t_tab *tab, va_list arg, int base);
uintmax_t			get_o(t_tab *tab, va_list arg);
uintmax_t			get_x(t_tab *tab, va_list arg);
void				print_zero_x(uintmax_t n, char hash, char x);
void				convert_x(t_tab *tab, uintmax_t num, char *str, int left);
void				print_c(t_tab *tab, va_list arg);
char				*print_f(t_tab *tab, va_list arg);
void				print_percent(t_tab *tab);
void				print_int_u(t_tab *tab, va_list arg);
void				print_int_d_i(t_tab *tab, va_list arg);
void				print_gap(t_tab *tab, char c, int len, int update_len);
int					valid_type(char type);
char				*ft_itoa_long(unsigned long int n);
char				*ft_itoa_base(uintmax_t num, uintmax_t base, char c);
void				ft_putnbrmax_fd(intmax_t n, int fd);
void				print_wchar(wint_t c, t_tab *tab);
void				oct_1(wint_t c);
void				oct_2(wint_t c);
void				oct_3(wint_t c);
void				oct_4(wint_t c);
char				*ft_ftoa_long(long double nbr, unsigned int p);
char				*ft_ftoa(double nbr, unsigned int p);
char				*redactor(char *s, t_tab *tab);
int					if_minus(char *s);
int					max(int a, int b, int c);
void				int_output(char *s, char *string, t_tab *tab);
void				init(t_tab *tab);

#endif
