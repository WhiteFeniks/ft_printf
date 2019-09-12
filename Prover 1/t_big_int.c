/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_big_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:47:17 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/12 03:11:11 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_big_int		*big_int(char *value, int is_freed, int reverse)
{
	t_big_int	*v;
	int			i;

	if ((v = malloc(sizeof(t_big_int))) == NULL)
		return (NULL);
	v->size = ft_strlen(value);
	if ((v->value = malloc((v->size + 2) * sizeof(char))) == NULL)
	{
		if (is_freed)
			free(value);
		free(v);
		return (NULL);
	}
	i = 0;
	while (i < v->size)
	{
		v->value[i] = value[reverse ? v->size - i - 1 : i];
		i++;
	}
	v->value[i] = '\0';
	v->value[i + 1] = '\0';
	if (is_freed)
		free(value);
	return (v);
}

t_big_int		*t_big_int_add(t_big_int *a, t_big_int *b, int bfree)
{
	t_big_int	*c;
	char		*str;
	int			r;
	int			i;
	char		tmp;

	r = 0;
	i = -1;
	c = big_int(a->size > b->size ? a->value : b->value, 0, 0);
	str = a->size > b->size ? b->value : a->value;
	while (str[++i] && (tmp = c->value[i]))
	{
		c->value[i] = ((r + (c->value[i] - '0') + (str[i] - '0')) % 10) + '0';
		r = (r + (tmp - '0') + (str[i] - '0')) / 10;
	}
	while (r > 0 && (tmp = (c->value[i] ? c->value[i] : '0')))
	{
		c->value[i++] = ((r + (tmp - '0')) % 10) + '0';
		r = (r + (tmp - '0')) / 10;
		c->value = g_charjoin(c->value, '\0');
		(c->size)++;
	}
	free_big_int(bfree & 1 ? a : NULL);
	free_big_int(bfree & 2 ? b : NULL);
	return (c);
}

t_big_int		*str_mul(char *str, int e, int is_freed)
{
	int			i;
	char		*c;
	char		tmp;
	int			r;
	t_big_int	*v;

	if (e == 0)
		v = big_int("0", 0, 0);
	else if (e == 1)
		v = big_int(str, 0, 0);
	else
	{
		i = -1;
		r = 0;
		c = ft_strdup(str);
		while (c[++i])
		{
			tmp = c[i];
			c[i] = ((r + (c[i] - '0') * e) % 10) + '0';
			r = (r + (tmp - '0') * e) / 10;
		}
		v = big_int(r ? g_charjoin(c, r + '0') : c, 1, 0);
	}
	free(is_freed ? str : NULL);
	return (v);
}

t_big_int		*t_big_int_mul(t_big_int *a, t_big_int *b, int bfree)
{
	t_big_int	*c;
	t_big_int	*tmp;
	char		*str;
	int			i;

	if (ft_strcmp(a->value, "0") == 0 || ft_strcmp(a->value, "0") == 0)
		c = big_int("0", 0, 0);
	else if (ft_strcmp(a->value, "1") == 0 || ft_strcmp(b->value, "1") == 0)
		c = big_int(ft_strcmp(a->value, "1") ? a->value : b->value, 0, 0);
	else
	{
		str = a->size > b->size ? b->value : a->value;
		c = str_mul(a->size > b->size ? a->value : b->value, str[0] - '0', 0);
		i = 0;
		while (++i < (a->size > b->size ? b->size : a->size) && str[i])
		{
			tmp = str_mul(g_strjoin(str_gen('0', i),
			a->size > b->size ? a->value : b->value, 0), str[i] - '0', 1);
			c = t_big_int_add(c, tmp, 3);
		}
	}
	free_big_int(bfree & 1 ? a : NULL);
	free_big_int(bfree & 2 ? b : NULL);
	return (c);
}

t_big_int		*t_big_int_pow(t_big_int *a, int b, int is_freed)
{
	t_big_int	*c;
	int			i;

	i = 0;
	c = big_int("1", 0, 0);
	while (i < b)
	{
		c = t_big_int_mul(c, a, 1);
		i++;
	}
	if (is_freed)
		free_big_int(a);
	return (c);
}
