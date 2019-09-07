/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 07:01:50 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/16 21:42:20 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		j--;
		i++;
	}
}

static int		ft_nb_digit(int n)
{
	int	nb;

	nb = 1;
	if (n <= 0)
	{
		nb++;
		n = -n;
	}
	while (n)
	{
		nb++;
		n = n / 10;
	}
	return (nb);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			i;
	unsigned	nbr;

	if ((str = malloc(ft_nb_digit(n))) == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	nbr = (n < 0) ? -n : n;
	i = 0;
	while (nbr > 0)
	{
		str[i++] = '0' + (nbr % 10);
		nbr = nbr / 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
