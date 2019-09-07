/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 01:23:52 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/13 05:08:34 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_check_validity(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (i == 0)
			{
				if (str[i] != '-' && str[i] != '+')
					break ;
			}
			else
				break ;
		}
		i = i + 1;
	}
	if (i == 0)
		return (0);
	else
		return ((char*)(str + i - 1));
}

int				ft_atoi(const char *str)
{
	int		number;
	int		base;
	char	*c;
	int		i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
				|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	c = ft_check_validity(str + i);
	if (!c)
		return (0);
	base = 1;
	number = 0;
	while (c >= (str + i) && *c != '-' && *c != '+')
	{
		number = number + (*c - '0') * base;
		base = base * 10;
		c = c - 1;
	}
	if (*(str + i) == '-')
		number = -number;
	return (number);
}
