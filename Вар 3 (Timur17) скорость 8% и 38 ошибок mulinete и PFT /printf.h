/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <wtorwold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:53:09 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/16 20:06:29 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct				s_pattern
{
	int						hash;
	int						minus;
	int						plus;
	int						space;
	int						zero;
	int						width;
	int						precision;
	int						point;
	int						h;
	int						hh;
	int						l;
	int						m;
	int						ll;
	int						z;
	int						j;
	int						help;
	char					type;
}							t_pattern;

typedef struct				s_strct
{
	int						neg;
	int						space;
	int						zero;
	int						f;
}							t_strct;

typedef	struct				s_formlfb
{
	unsigned long int		mantisa : 64;
	unsigned				exponent : 15;
	unsigned				sign : 1;
}							t_formlfb;

typedef	union				u_formlf
{
	long double				f;
	t_formlfb				bytes;
}							t_form_lf;

void						ft_putchar_help(char c, int *count);
uintmax_t					va_arg_u(va_list factor, t_pattern *tmp);
void						ft_putnbr_max_u(uintmax_t n);
void						ft_putnbr_max(intmax_t n, int f);
void						ft_print_main(t_pattern tmp,
		char **ld, char **ost, int byte);
void						ft_print_main2(t_pattern tmp,
		char **ld, char **ost, int byte);
int							ft_sign(int nbr);
void						ft_round(char **ost, char **ld, t_pattern tmp);
void						ft_roundtwo(char **ost,
		t_pattern tmp, char **one, char **tofree);
void						ft_roundthr(char **one,
		t_pattern tmp, char **ld, char **ost);
int							ft_notzero(char *str);
char						*ft_zerostr(void);
void						ft_print_krit(t_pattern tmp, double nbr, int step);
void						ft_print_krit2(t_pattern tmp,
		double nbr, int step, int index);
char						*ft_stept(int step);
char						*ft_multt(char *f);
char						*ft_dividet(char *f);
char						*ft_substract(char *first, char *second);
char						*ft_sum(char *first, char *second);
void						ft_strcapitalize(char **str, uintmax_t nmr);
void						ft_privedenie(t_pattern tmp, uintmax_t *ptr);
void						print_u(t_pattern tmp, va_list factor);
void						print_s(t_pattern tmp, va_list factor);
void						print_c(t_pattern tmp, char c);
void						ft_print_f(t_pattern tmp, long double nbr);
intmax_t					va_arg_help(va_list factor, t_pattern *tmp);
void						put_cast(t_pattern *tmp,
		const char *format, int *i);
int							ft_cast(char c);
void						print_help (int pre, intmax_t *digit);
int							ft_num(const char *format, int *i, va_list factor);
void						new_pattern(t_pattern *tmp);
void						new_strc(t_strct *help);
int							type(char c);
int							ft_flag(char c);
void						addflag(t_pattern *tmp, char c);
void						print_int(t_pattern tmp, va_list factor);
int							print(t_pattern tmp, va_list factor);
int							ft_search(char c, t_pattern tmp, va_list factor);
int							ft_parse(const char *format,
		int *i, t_pattern *tmp, va_list factor);
int							ft_printf(const char *format, ...);
char						*ft_itoa_base(uintmax_t value, long int base);
void						ft_print_p(t_pattern tmp, uintmax_t ptr);
#endif
