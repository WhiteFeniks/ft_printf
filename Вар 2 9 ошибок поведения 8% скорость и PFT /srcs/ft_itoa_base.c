/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_itoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 08:04:09 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 08:04:11 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_or(u_int64_t n, u_int64_t b)
{
	int		a;

	a = 1;
	while (n / b)
	{
		n /= b;
		++a;
	}
	return (a);
}

char	*u_itoa_base(u_int64_t n, u_int64_t b, int c)
{
	int		l;
	char	*s;

	if (b < 2 || b > 16 || b == 10)
		return (NULL);
	l = ft_or(n, b);
	if (!(s = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	s[l] = '\0';
	n == 0 ? s[0] = '0' : 0;
	while (n)
	{
		if (n % b < 10)
			s[--l] = n % b + 48;
		else
			s[--l] = c ? n % b + 87 : n % b + 55;
		n /= b;
	}
	return (s);
}
