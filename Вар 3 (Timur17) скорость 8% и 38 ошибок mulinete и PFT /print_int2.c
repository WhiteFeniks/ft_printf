/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <wtorwold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:53:09 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/16 20:15:58 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				print_help(int pre, intmax_t *digit)
{
	int			num;

	if (*digit < 0)
	{
		ft_putchar('-');
		*digit = *digit * (-1);
	}
	num = pre - ft_countdigit(*digit);
	while (num-- > 0)
		ft_putnbr(0);
}

intmax_t			va_arg_help(va_list factor, t_pattern *tmp)
{
	if (tmp->l == 1)
		return (va_arg(factor, long));
	else if (tmp->ll == 1)
		return (va_arg(factor, long long));
	else if (tmp->h == 1 && tmp->j != 1 && tmp->z != 1)
		return ((short)va_arg(factor, int));
	else if (tmp->hh == 1)
		return ((char)va_arg(factor, int));
	else if (tmp->z == 1)
		return (va_arg(factor, size_t));
	else if (tmp->j == 1)
		return (va_arg(factor, intmax_t));
	else
		return (va_arg(factor, int));
}
