/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 12:23:51 by shunt             #+#    #+#             */
/*   Updated: 2019/08/07 01:50:18 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_rg(char *s, int a, unsigned short int d)
{
	int		i;
	int		k;
	char	*t;
	char	*c;

	c = NULL;
	k = ft_strlen(s);
	i = t_str(s, &t);
	if (k != i)
		c_str(s, &c, i, k);
	i = -1;
	k = 0;
	while (t[++i] && k < a)
		if (t[i] >= '0' && t[i] <= '9')
			++k;
	if (t[i])
		t[i] == '.' ? rndg_z(&t, i, d) : rndg(&t, i);
	(d & F_OCT) ? 0 : wzrs(&t);
	s_str(&s, &t, &c);
	return (s);
}
