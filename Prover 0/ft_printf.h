/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:01:51 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/23 16:05:33 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"

size_t				g_count;

typedef enum		e_del
{
	FIRST,
	SECOND,
	BOTH
}					t_del;

typedef enum		e_size
{
	DEF,
	HH,
	H,
	L,
	LL,
	J,
	Z
}					t_size;

typedef struct		s_saver
{
	char			hash;
	char			minus_null;
	char			plus_space;
	int				width;
	int				precision;
	t_size			size;
	char			specifier;

}					t_saver;
void				ft_write(int fildes, const void *buf, size_t nbyte);
void				ft_put_char(const char c);
void				ft_put_string(const char *str);
char				*ft_lower(char *str);
char				*ft_utoa_base(unsigned long long value, int base);
t_saver				*create_struct(void);
int					is_flag(const char *string, size_t i);
int					is_size(const char *string, size_t i);
t_size				get_size(const char *string, size_t i);
size_t				parse_flags(const char *format, size_t i, t_saver *saver);
size_t				parse_width(const char *format, size_t i, t_saver *saver,
					va_list a);
size_t				parse_prec(const char *format, size_t i, t_saver *saver,
					va_list a);
size_t				parse_size(const char *format, size_t i, t_saver *saver);
size_t				parse_specif(const char *format, size_t i, t_saver *saver);
size_t				parse_it(const char *format, size_t i, t_saver *saver,
					va_list a);
char				*convert_wstrtostr(wchar_t *str, int max_len);
char				*ft_join(char *str1, char *str2, t_del string);
long long			get_number_arg(t_saver *saver, va_list arg);
unsigned long long	get_unsigned_number_arg(t_saver *saver, va_list arg);
char				*add_precision(t_saver *saver, char *str);
char				*add_flags(t_saver *saver, char *str);
char				*add_min_width(t_saver *saver, char *str);
char				*get_decimal_str(t_saver *saver, va_list arg);
char				*get_uns_decimal_str(t_saver *saver, va_list arg);
char				*get_octal_str(t_saver *saver, va_list arg);
char				*get_hex_str(t_saver *saver, va_list arg);
char				*get_binary_str(t_saver *saver, va_list arg);
void				print_char(t_saver *saver, va_list arg);
void				print_string(t_saver *saver, va_list arg);
void				print_number(t_saver *saver, va_list arg);
void				print_pointer(t_saver *saver, va_list arg);
int					arg_print(t_saver *saver, va_list arg);
int					ft_printf(const char *restrict format, ...);

#endif
