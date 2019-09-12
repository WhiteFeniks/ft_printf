/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:17:49 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/21 03:07:31 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "t_big_types.h"
# define ULL unsigned long long
# define LL long long
# define LLL __int128
# define ULLL unsigned __int128
# define T_FLOAT 1
# define T_DOUBLE 2
# define T_LDOUBLE 3
# define ABS(x) (x < 0) ? -x : x

typedef	struct		s_info
{
	int				prc;
	int				fields;
	int				sign;
	int				minus;
	int				space;
	int				diaz;
	char			fill;
	char			*flag;
	char			cur_f;
	int				index;
	int				nb_p;
	char			*str;
}					t_info;

typedef struct		s_float                          //
{
	short			type;
	short			s;
	short			e;
	short			exp;
	short			i_p;
	char			*m;
}					t_float;

t_float				*extract_double(va_list *ap, int is_dbl);   //

t_float				*extract_l_double(va_list *ap);    //

char				*g_charjoin(char *str, char c);

char				*g_strjoin(char *str, char *s, int free_str);

int					char_in(char c, char *str);

int					ft_nb_digit(LL nb);

char				*str_gen(char c, int len);

char				*ft_itobase(ULL nb, char *base);

char				*ft_s_itobase(LL nb, char *base);

void				ft_init_info(t_info *info);

void				ft_reset_info(t_info *info);

void				ft_free_info(t_info *info);

void				ft_parse(const char *format, t_info *info, va_list *ap);

void				ft_process_o_b(t_info *info, va_list *ap, char *base);

void				ft_process_hex(t_info *info, va_list *ap);

void				ft_process_pointer(t_info *info, va_list *ap);

void				ft_process_s_int(t_info *info, va_list *ap);

void				ft_process_u_int(t_info *info, va_list *ap);

void				ft_process_char(t_info *info, va_list *ap);

void				ft_process_chr(t_info *info, char c);

void				ft_process_str(t_info *info, va_list *ap);

void				ft_process_real(t_info *info, va_list *ap);

int					ft_val(LL a);

char				*special_f(t_float *f, t_info *info);   //

char				*ft_strrev(char *str);

void				ft_concat_str(char **str, char **pr, char **tmp,
	t_info *info);

char				*ft_round(char *str, t_info *info);

void				free_big_int(t_big_int *a);

char				*ft_f_to_str(t_float *f);   //

LL					ft_calc_point(t_float *f, t_big_int *t);  //

t_big_int			*calc_real(t_float *f, t_big_int **t);  //

int					ft_printf(const char *format, ...);

#endif
