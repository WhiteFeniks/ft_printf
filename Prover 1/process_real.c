/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_real.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:29:08 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/25 09:06:19 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_big_int	*calc_real(t_float *f, t_big_int **t)
{
	t_big_int	*tab[6];
	int			i;

	i = -1;
	tab[0] = big_int("0", 0, 0);
	tab[1] = big_int("5", 0, 0);
	tab[2] = big_int("10", 0, 1);
	tab[3] = big_int("2", 0, 0);
	f->m = g_strjoin(ft_strdup(f->i_p ? "1" : "0"), f->m, 1);
	while (f->m[++i])
	{
		tab[4] = big_int(g_charjoin(ft_strdup(""), f->m[i]), 1, 0);
		tab[5] = t_big_int_pow(tab[2], (size_t)i > ft_strlen(tab[0]->value) ?
		i - ft_strlen(tab[0]->value) : 1, 0);
		tab[0] = t_big_int_mul(tab[0], tab[5], 3);
		tab[4] = t_big_int_mul(tab[4], t_big_int_pow(tab[1], i, 0), 3);
		tab[0] = t_big_int_add(tab[0], tab[4], 3);
	}
	tab[4] = t_big_int_pow((f->e - f->exp) > 0 ? tab[3] : tab[1],
	(f->e - f->exp) > 0 ? (f->e - f->exp) : (f->exp - f->e), 0);
	free_big_int(tab[1]);
	free_big_int(tab[2]);
	free_big_int(tab[3]);
	*t = tab[0];
	return (t_big_int_mul(tab[0], tab[4], 2));
}

double		str_to_double(char *s)
{
	double		o;
	double		r;
	int			i;

	i = ft_strlen(s) - 1;
	o = 0.1;
	r = (s[i] - '0');
	while (--i >= 0)
	{
		r += (s[i] - '0') * o;
		o /= 10.0;
	}
	return (r);
}

LL			ft_calc_point(t_float *f, t_big_int *t)
{
	t_big_int	*a;
	LL			r;
	double		d;
	double		e;

	a = (f->e > f->exp) ? t_big_int_pow(big_int("2", 0, 0), f->e - f->exp, 1)
	: t_big_int_pow(big_int("2", 0, 0), f->exp - f->e, 1);
	d = str_to_double(t->value);
	e = str_to_double(a->value);
	d = d * e;
	r = f->e >= f->exp ? (LL)ft_strlen(a->value) + 1
	: -(LL)ft_strlen(a->value) + 1;
	if (r > 0)
		r += d / 10;
	free_big_int(a);
	return (r);
}

char		*ft_get_real(t_info *info, va_list *ap)
{
	t_float		*f;

	if (!info->flag || ft_strlen(info->flag) == 0)
		f = extract_double(ap, 0);
	else
	{
		if (!ft_strcmp(info->flag, "L") || !ft_strcmp(info->flag, "ll"))
			f = extract_l_double(ap);
		else if (ft_strcmp(info->flag, "l") == 0)
			f = extract_double(ap, 1);
		else
			f = extract_double(ap, 0);
	}
	if (((f->e == 2 * f->exp + 1) && ft_strncmp(f->m,
	"0000000000000000000000000000000000000000000000000000", 52) == 0)
	|| ((f->e == 2 * f->exp + 1) && ft_strncmp(f->m,
	"0000000000000000000000000000000000000000000000000000", 52))
	|| (f->e == 0 && !ft_atoi(f->m)))
		return (special_f(f, info));
	return (ft_f_to_str(f));
}

void		ft_process_real(t_info *info, va_list *ap)
{
	char	*str;
	char	*tmp;
	int		len;
	char	*pr;

	str = ft_get_real(info, ap);
	info->prc = info->prc == -2 ? 6 : info->prc;
	pr = ft_strdup(info->sign && !char_in(str[0], "n-N") ? "+" : "");
	if (str[0] == '-')
	{
		free(pr);
		pr = g_strjoin(ft_strdup(""), str + 1, 0);
		free(str);
		str = pr;
		pr = ft_strdup("-");
	}
	else
		pr = info->space ? g_strjoin(ft_strdup(" "), pr, 1) : pr;
	str = ft_round(str, info);
	len = info->fields - ft_val(ft_strchr(str, '.') - str) - (info->prc ? 0
	: ft_strlen(str)) - info->prc - (info->prc || info->diaz) - ft_strlen(pr);
	len += char_in(str[0], "niNI") || char_in(str[1], "aiAI") ? info->prc : 0;
	tmp = len > 0 ? str_gen(info->fill, len) : ft_strdup("");
	ft_concat_str(&str, &pr, &tmp, info);
	info->str = g_strjoin(info->str, str, 1);
}
