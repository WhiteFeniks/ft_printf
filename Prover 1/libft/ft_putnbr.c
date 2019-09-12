/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 07:43:44 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/04 07:53:08 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static	void	ft_printchar(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			ft_putnbr(-n);
		}
		else if (n < 10)
			ft_printchar('0' + n);
		else
		{
			ft_putnbr(n / 10);
			ft_printchar('0' + (n % 10));
		}
	}
}
