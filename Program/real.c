/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:44:04 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/13 20:50:13 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_btoi(char *c, short len)
{
	int		p;
	int		e;
	int		i;

	i = len - 1;
	e = 0;
	p = 1;
	while (i >= 0)
	{
		e += p * (c[i] - '0');
		p *= 2;
		i--;
	}
	return (e);
}

t_float				*extract_double(va_list *ap, int is_dbl)
{
	char		c[65];
	int			i;
	double		d;
	t_float		*f;
	ULL			*e;

	if ((f = malloc(sizeof(t_float))) == NULL)
		return (NULL);
	ft_memset(f, 0, sizeof(t_float));
	i = 63;
	d = va_arg(*ap, double);
	e = (ULL*)&d;
	while (i >= 0)
	{
		c[i--] = ((*e) % 2) + '0';
		(*e) >>= 1;
	}
	f->s = c[0] - '0';
	f->e = ft_btoi(c + 1, 11);
	f->exp = 1023;
	f->m = ft_strsub(c, 12, 52);
	f->i_p = 1;
	f->type = is_dbl ? T_DOUBLE : T_FLOAT;
	return (f);
}

t_float				*extract_l_double(va_list *ap)
{
	char			c[81];
	int				i;
	long double		d;
	t_float			*f;
	ULLL			*e;

	if ((f = malloc(sizeof(t_float))) == NULL)
		return (NULL);
	ft_memset(f, 0, sizeof(t_float));
	i = 79;
	d = va_arg(*ap, long double);
	e = (ULLL*)&d;
	while (i >= 0)
	{
		c[i--] = ((*e) % 2) + '0';
		(*e) >>= 1;
	}
	f->s = c[0] - '0';
	f->e = ft_btoi(c + 1, 15);
	f->exp = 16383;
	f->m = ft_strsub(c, 17, 63);
	f->i_p = c[16] - '0';
	f->type = T_LDOUBLE;
	return (f);
}

char				*special_f(t_float *f, t_info *info)
{
	char	*str;
	int		toup;

	str = NULL;
	toup = (info->cur_f == 'F');
	if ((f->e == 2 * f->exp + 1) && ft_strncmp(f->m,
	"0000000000000000000000000000000000000000000000000000", 52) == 0)
	{
		str = f->s ? ft_strdup("-") : ft_strdup("");
		str = g_strjoin(str, toup ? "INF" : "inf", 0);
	}
	else if ((f->e == 2 * f->exp + 1) && ft_strncmp(f->m,
	"0000000000000000000000000000000000000000000000000000", 52))
		str = ft_strdup(toup ? "NAN" : "nan");
	else if (f->e == 0 && !ft_atoi(f->m))
		str = f->s ? ft_strdup("-0") : ft_strdup("0");
	free(f->m);
	free(f);
	return (str);
}
