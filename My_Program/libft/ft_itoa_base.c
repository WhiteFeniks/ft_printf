/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:34:40 by mbodak            #+#    #+#             */
/*   Updated: 2017/02/17 11:40:24 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	int		i;
	int		minus;
	long	tmp;
	char	*res;
	char	*b;

	b = "0123456789ABCDEF";
	i = 1;
	minus = 0;
	tmp = value;
	while (value /= base)
		i++;
	if (tmp < 0 && ((base == 10) || (minus = 1)))
		tmp = -tmp;
	res = (char *)malloc(sizeof(char) * ((i + minus) + 1));
	res[i] = '\0';
	while (--i >= 0)
	{
		res[i] = b[tmp % base];
		tmp /= base;
	}
	if (minus && base == 10)
		res[i] = '-';
	return (res);
}
