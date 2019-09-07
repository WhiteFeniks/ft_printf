/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:07:30 by shunt             #+#    #+#             */
/*   Updated: 2019/06/20 00:07:33 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_st(char **t, int i, unsigned short f, int a)
{
	int		k;

	if ((*t)[i - 1] != '.')
	{
		k = i;
		while (--i >= 0 && (*t)[i] != '.')
			;
		if (k - i - 1 < (int)a)
			zrs(t, a, i);
		else
			a ? rnd(t, a, i) : rnd_z(t, i, a, f);
	}
	else
		e_zrs(t, a, i);
}

char		*ft_round(char *s, size_t a, unsigned short f)
{
	int		i;
	int		k;
	char	*t;
	char	*c;

	i = -1;
	while (s[++i] && s[i] != '.')
		;
	if (!s[i])
		return (s);
	c = NULL;
	k = ft_strlen(s);
	i = t_str(s, &t);
	if (k != i)
		c_str(s, &c, i, k);
	ft_st(&t, i, f, a);
	s_str(&s, &t, &c);
	return (s);
}
