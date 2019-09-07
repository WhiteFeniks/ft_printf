/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:01:19 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:07:46 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	res;
	int					negative;
	int					dig;

	i = 0;
	negative = 1;
	res = 0;
	dig = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' ' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9' && dig++ < 19)
		res = res * 10 + (unsigned long long)(str[i++] - 48);
	if (res > 9223372036854775807 || dig > 19)
		return (negative == -1 ? 0 : -1);
	return ((int)(res * negative));
}
