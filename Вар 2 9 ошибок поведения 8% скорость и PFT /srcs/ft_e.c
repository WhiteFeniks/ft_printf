/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 01:37:48 by shunt             #+#    #+#             */
/*   Updated: 2019/08/06 22:56:40 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_len(int k)
{
	int		l;

	l = 4;
	while (k / 100)
	{
		++l;
		k /= 100;
	}
	return (l);
}

static char	*ifz(int a, int b)
{
	char	*r;

	r = b ? (char *)malloc(sizeof(char) * 8) : (char *)malloc(sizeof(char) * 7);
	if (!r)
		return (NULL);
	r[0] = b ? '-' : '0';
	r[1] = b ? '0' : '.';
	if (b)
		r[2] = '.';
	else
		r[2] = a ? 'e' : 'E';
	if (b)
		r[3] = a ? 'e' : 'E';
	else
		r[3] = '+';
	r[4] = b ? '+' : '0';
	r[5] = '0';
	r[6] = b ? '0' : '\0';
	b ? r[7] = '\0' : 0;
	return (r);
}

static char	*ft_nr(char *s, int *i, int *l, int *k)
{
	char	*r;

	if (s[++(*i)] != '0')
	{
		while (s[(*i)] && s[(*i)] != '.')
			++(*i);
		*k = (s[0] == '-') ? *i - 2 : *i - 1;
	}
	else
	{
		*i += 2;
		while (s[(*i)] == '0')
			++(*i);
		*k = (s[0] == '-') ? *i - 2 : *i - 1;
	}
	*l = ft_strlen(s) + ft_len(*k);
	if (!(r = (char *)malloc(sizeof(char) * (*l + 1))))
		return (NULL);
	r[(*l)] = '\0';
	*i = 0;
	while (s[(*i)] && (s[(*i)] == '-' || s[(*i)] == '0' || s[(*i)] == '.'))
		++(*i);
	return (r);
}

static void	f(char *s, int i, char **r, int k)
{
	int		j[2];

	j[0] = 0;
	j[1] = ft_strlen(s) + ft_len(k);
	s[0] == '-' ? (*r)[j[0]++] = '-' : 0;
	(*r)[j[0]] = (!s[i]) ? '0' : s[i];
	(*r)[++j[0]] = '.';
	while (s[i] && s[++i])
		s[i] != '.' ? (*r)[++j[0]] = s[i] : 0;
	(*r)[++j[0]] = 'e';
	if (s[0] == '-')
		(*r)[++j[0]] = (s[1] == '0') ? '-' : '+';
	else
		(*r)[++j[0]] = (s[0] == '0') ? '-' : '+';
	if (k < 10)
	{
		(*r)[++j[0]] = '0';
		(*r)[++j[0]] = k + 48;
	}
	else
		while (k)
		{
			(*r)[--j[1]] = k % 10 + 48;
			k /= 10;
		}
}

char		*ft_e(long double e, int a)
{
	char	*s;
	char	*r;
	int		i[4];

	if (!(s = ft_fld(e, a)))
		return (NULL);
	if (s[0] == '0' || (s[0] == '-' && s[1] == '0'))
		return (s[0] == '-' ? ifz(a, 1) : ifz(a, 0));
	if (s[0] == 'i' || s[0] == 'I' || s[0] == 'n' ||
		s[0] == 'N' || s[1] == 'i' || s[1] == 'I')
		return (s);
	i[0] = (s[0] == '-') ? 0 : -1;
	if (!(r = ft_nr(s, &i[0], &i[3], &i[2])))
		return (NULL);
	f(s, i[0], &r, i[2]);
	i[0] = -1;
	if (!a)
	{
		while (r[++i[0]] && r[i[0]] != 'e')
			;
		r[i[0]] = 'E';
	}
	free(s);
	return (r);
}
