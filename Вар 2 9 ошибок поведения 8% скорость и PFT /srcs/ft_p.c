/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 04:58:32 by shunt             #+#    #+#             */
/*   Updated: 2019/06/18 04:58:34 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_p(unsigned long long p)
{
	char	*s;
	char	*r;
	int		i;

	if (p)
	{
		s = u_itoa_base(p, 16, 1);
		r = (char *)malloc(sizeof(char) * (ft_strlen(s) + 3));
		r[0] = '0';
		r[1] = 'x';
		i = -1;
		while (s[++i])
			r[i + 2] = s[i];
		r[i + 2] = '\0';
		free(s);
	}
	else
	{
		r = (char *)malloc(sizeof(char) * 4);
		r[0] = '0';
		r[1] = 'x';
		r[2] = '0';
		r[3] = '\0';
	}
	return (r);
}
