/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_fp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:11:06 by shunt             #+#    #+#             */
/*   Updated: 2019/06/30 17:11:07 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_order_u(u_int64_t n)
{
	int		a;

	a = 1;
	while (n >= 10)
	{
		n /= 10;
		a++;
	}
	return (a);
}

static int	ft_order_s(int64_t n)
{
	int		a;

	a = n < 0 ? 2 : 1;
	if (n < 0)
		while (n <= -10)
		{
			n /= 10;
			a++;
		}
	else
		while (n >= 10)
		{
			n /= 10;
			a++;
		}
	return (a);
}

char		*u_itoa(u_int64_t n)
{
	char	*r;
	int		a;

	a = ft_order_u(n);
	if ((r = (char *)malloc(sizeof(char) * (a + 1))))
	{
		r[a] = '\0';
		while (--a >= 0)
		{
			r[a] = (n % 10) + 48;
			n /= 10;
		}
		return (r);
	}
	return (NULL);
}

char		*s_itoa(int64_t n)
{
	char	*r;
	int		a;

	a = ft_order_s(n);
	if ((r = (char *)malloc(sizeof(char) * (a + 1))))
	{
		r[a] = '\0';
		r[0] = n == 0 ? '0' : '-';
		while (n)
		{
			r[--a] = ((n % 10) >= 0) ? (n % 10) + 48 : ((n % 10) * -1) + 48;
			n /= 10;
		}
		return (r);
	}
	return (NULL);
}
