/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 04:54:52 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/21 03:16:37 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_concat_str(char **str, char **pr, char **tmp, t_info *info)
{
	if (info->diaz && !info->prc && ft_tolower(info->cur_f) == 'f')
		*tmp = g_strjoin(*tmp, str_gen(info->fill, 2 * ft_strlen(*str)
		< (ULL)(ABS(info->fields)) ? ft_val(ft_strlen(*str))
		: info->fields - ft_strlen(*str) - info->space - info->sign), 1);
	if (ft_tolower(info->cur_f) == 'f' && (char_in((*str)[1], "aniANI")))
	{
		free(*tmp);
		*tmp = str_gen(' ', info->fields - ft_strlen(*str));
	}
	if (info->minus)
	{
		*pr = g_strjoin(*pr, str_gen('0', info->cur_f == 'f'
		|| info->cur_f == 'F' ? 0 : info->prc - ft_strlen(*str)), 1);
		*str = g_strjoin(g_strjoin(*pr, *str, 1), *tmp, 1);
	}
	else
	{
		*pr = info->fill == ' ' ? g_strjoin(*tmp, *pr, 1) : g_strjoin(*pr,
		*tmp, 1);
		*pr = g_strjoin(*pr, str_gen('0', ft_tolower(info->cur_f) == 'f' ? 0
		: info->prc - ft_strlen(*str)), 1);
		*str = g_strjoin(*pr, *str, 1);
	}
}

int		is_midlway(char *s)
{
	if (!s || *s != '5')
		return (0);
	while (*(++s))
	{
		if (*s != '0')
			return (0);
	}
	return (1);
}

int		do_rounding(char *str, char *c, int j)
{
	int		len;
	int		r;
	char	tmp;

	if (c[j] < '5')
		return (0);
	len = ft_strlen(str) - 1;
	r = c[j] == '5' && is_midlway(c + j) ? 0 : 1;
	if (c[j] == '5' && is_midlway(c + j))
		if ((str[len] - '0') % 2)
		{
			r = ((str[len] - '0') + 1) / 10;
			str[len] = (((str[len] - '0') + 1) % 10) + '0';
			len--;
		}
	while (r > 0 && len >= 0)
	{
		if (str[len] == '.')
			len--;
		tmp = str[len];
		str[len] = ((r + (tmp - '0')) % 10) + '0';
		r = (r + (tmp - '0')) / 10;
		len--;
	}
	return (r);
}

char	*ft_round(char *str, t_info *info)
{
	char	*s;
	char	*tmp;
	int		len;
	int		i;
	int		j;

	if (char_in(str[0], "niNI") || char_in(str[1], "aniANI"))
		return (str);
	tmp = str;
	len = ft_strchr(str, '.') ? (int)(ft_strchr(str, '.') - str) : 1;
	i = 0;
	s = g_strjoin(ft_strdup(""), ft_strsub(str, 0, len), 1);
	s = info->prc || info->diaz ? g_charjoin(s, '.') : s;
	str = str + len + 1;
	i = -1;
	while (++i < info->prc && str[i])
		s = g_charjoin(s, str[i]);
	j = i;
	while (++i < info->prc + (!info->diaz || info->prc))
		s = g_charjoin(s, '0');
	if (str[j] != '\0')
		j = do_rounding(s, str, j);
	s = j && str[j] ? g_strjoin(ft_strdup("1"), s, 1) : s;
	free(tmp);
	return (s);
}

char	*ft_f_to_str(t_float *f)
{
	t_big_int	*a;
	t_big_int	*t;
	int			i;
	LL			p;
	char		*str;

	a = calc_real(f, &t);
	i = 0;
	p = ft_calc_point(f, t);
	str = p <= 0 ? g_strjoin(g_strjoin(ft_strdup(a->value),
	str_gen('0', -p), 1), ".0", 0) : ft_strdup("");
	if (p > 0)
	{
		while ((LL)ft_strlen(a->value + i) > p - 1)
			str = g_charjoin(str, a->value[i++]);
		str = g_strjoin(g_charjoin(str, '.'), a->value + i, 0);
	}
	free_big_int(a);
	free_big_int(t);
	free(f->m);
	free(f);
	return (ft_strrev(f->s ? g_strjoin(str, "-", 0) : str));
}
