/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:16:20 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:08:14 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	negative_itoa(int *n, int *neg)
{
	if (*n < 0)
	{
		*neg = 1;
		*n *= -1;
	}
}

char			*ft_itoa(int n)
{
	int		numb;
	int		neg;
	int		len;
	char	*res;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negative_itoa(&n, &neg);
	numb = n;
	len = 1 + neg;
	while (numb /= 10)
		len++;
	if (!(res = ((char *)malloc(sizeof(char) * (len + 1)))))
		return (0);
	res[len] = '\0';
	while (len-- > 0)
	{
		res[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
