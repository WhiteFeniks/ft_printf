/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 22:49:05 by shunt             #+#    #+#             */
/*   Updated: 2019/06/02 22:50:07 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

/*
**  DIFFERENT
*/

# define SUCCESS		1

/*
**  FLAGS (MASKS)
*/

# define F_MINUS         (1u << 0u)
# define F_PLUS          (1u << 1u)
# define F_SPACE         (1u << 2u)
# define F_OCT           (1u << 3u)
# define F_ZERO          (1u << 4u)

/*
**  SIZE (MASKS)
*/

# define LONG_INT        (1u << 0u)
# define LONG_LONG_INT   (1u << 1u)
# define SHORT_INT       (1u << 2u)
# define SIGNED_CHAR     (1u << 3u)
# define INT_MAXX        (1u << 4u)
# define SIZE_T          (1u << 5u)
# define PTRDIFF_T       (1u << 6u)
# define INT_64          (1u << 7u)

/*
**  STRUCTURES
*/

typedef struct			s_rd
{
	wchar_t				*mod2;
	char				*mod;
	char				mod_smb;
	int					sign;
	unsigned short int	flag;
	unsigned short int	size;
	size_t				smb_cnt;
	size_t				kostil;
	long				width;
	long				prs;
	size_t				strlen;
	struct s_rd			*next;
	struct s_rd			*prev;
	int					zero;
}						t_rd;

typedef struct			s_out
{
	char				*buf;
	int					cnt;
}						t_out;

typedef struct			s_printf
{
	va_list				ap;
	t_rd				*read;
	t_out				output;
}						t_printf;

typedef struct			s_ptfrst
{
	char				*res;
	char				*tmp2;
	int					tmp;
	int					i;
	int					b;
}						t_pft;

typedef struct			s_chckn
{
	char				*res;
	char				*tmp2;
	int					tmp;
	int					i;
	int					b;
}						t_check;

typedef struct			s_width
{
	unsigned long		strlen;
	unsigned long		i;
	int					b;
	char				*res;
	char				*tmp;
}						t_wid;

/*
**  UNION
*/

typedef union			u_flts
{
	long double			u;
	short				y[5];
}						t_flts;

/*
**  READER
*/

void					ft_reader(t_rd **read, va_list *ap, const char *format,
						t_out *out);
void					ft_chck_flags(t_rd **read, const char *format);
void					ft_mod(t_rd **read, const char *format, va_list **ap,
						t_out *out);
void					ft_chck_size(t_rd **rd, const char *format);
void					ft_chck_precision(t_rd **read, const char *format,
						va_list **ap);
void					ft_chck_wdth(t_rd **read, const char *format,
						va_list **ap);
void					ft_rd(t_rd **rd, va_list *ap, const char *ft,
						t_out **out);
void					ft_put_percent(t_rd **read);
int						ft_k(t_rd **read, const char *format,
						va_list **ap, t_out *out);
void					chck_b(t_rd **read, va_list **ap);
void					chck_c(t_rd **read, va_list **ap);
void					chck_di(t_rd **read, va_list **ap, int a);
void					chck_e(t_rd **read, va_list **ap, int a);
void					chck_f(t_rd **read, va_list **ap, int a);
void					chck_g(t_rd **read, va_list **ap, int a);
void					chck_o(t_rd **read, va_list **ap);
void					chck_p(t_rd **read, va_list **ap);
void					chck_sr(t_rd **read, va_list **ap, int a);
void					chck_x(t_rd **read, va_list **ap);
void					chck_xu(t_rd **read, va_list **ap);
void					chck_u(t_rd **read, va_list **ap);
void					ft_cycle(t_rd **rd, const char *format);
int						chck_nthng(const char *format, t_out *output,
						t_rd **rd);
void					ft_cycle2(t_rd **read, const char *format, int	*r);
void					ft_check_2(const char *format, t_rd **read, t_check *c);

/*
**  MAIN
*/

void					ft_putbuf(char *s, int b);
char					*ft_bufjoin(char *s1, char *s2, int b1, int b2);
void					ft_free_lists(t_rd **read);
int						ft_printf(const char *format, ...);
int						ft_pt_frst(const char *format,
						t_out *output, t_rd **rd);
void					ft_next_list(t_printf *p, const char *format);
int						ft_prepare(t_printf *p, const char *format);

/*
**  SOLVER
*/

void					ft_cycle6(t_wid *q, t_rd **read);
int						ft_solver(t_rd **read, t_out *output);
int						ft_app_fl(t_rd **read);
int						ft_app_d_prs(t_rd **read);
int						ft_app_width(t_rd **read);
int						ft_app_size(t_rd **read, t_out **output);
int						ft_put_out(t_rd **read, t_out **output);
int						ft_add_pl(t_rd **read);
int						ft_add_sharp(t_rd **read);

/*
**  OUTPUT
*/

void					ft_out_cnt(t_out *output);

/*
**  TYPES
*/

int						t_str(char *s, char **t);
int						mexp(t_flts l);
char					*ft_u(u_int64_t n);
char					*ft_c(wchar_t c, int a, t_rd **read);
char					*ft_e(long double e, int a);
char					*ft_ox(u_int64_t o, int a, int b);
char					*ft_p(unsigned long long p);
char					*ft_fld(long double f, int c);
char					*ft_g(long double g, int a, size_t b,
						unsigned short int c);
char					*ft_s(char *s);
char					*mantis(t_flts l);
void					str_ad(char **s1, char *s2);
void					str_ml(char **s1, int m);
char					*pw_to_str(int a, int b);
char					*int_p(int e, char *man);
char					*fr_p(int i, char *man);
char					*add_z(char *s, int z);
char					*res_w_fr(int e, char *in, char *fr, int sign);
char					*res_o_fr(char *in, int sign);
char					*u_itoa_base(u_int64_t n, u_int64_t b, int c);
char					*ft_round(char *s, size_t a, unsigned short f);
void					zrs(char **s, int a, int i);
void					e_zrs(char **s, int a, int i);
void					c_str(char *s, char **c, int i, int k);
void					s_str(char **s, char **t, char **c);
char					*fld_edge(char **man, int sign, int c);
void					rnd_z(char **s, int i, size_t a, unsigned short f);
void					rnd(char **s, int a, int i);
void					rndg(char **s, int i);
void					rndg_z(char **s, int i, unsigned short int c);
char					*ft_rg(char *s, int a, unsigned short int d);
char					*s_itoa(int64_t n);
char					*u_itoa(u_int64_t n);
void					wzrs(char **t);
char					*ft_ro(char **s, size_t prs, t_rd **read, int l);
long long				pw(long long n, int p);

#endif
