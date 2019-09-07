/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:32:51 by mbodak            #+#    #+#             */
/*   Updated: 2016/12/17 16:56:56 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long int	result;
	int					minus;
	size_t				i;

	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	result = 0;
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		result = result * 10 + (str[i] - 48);
		if (result >= 9223372036854775807 && minus == 1)
			return (-1);
		else if (result > 9223372036854775807 && minus == -1)
			return (0);
		i++;
	}
	return ((int)(result * minus));
}
