/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <wtorwold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:53:09 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/16 20:15:44 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_countdigit_u(uintmax_t dig)
{
	int				num;

	num = 1;
	if (dig / 10 == 1844674407370955161 && dig % 10 <= 5)
		return (20);
	while (dig > 9)
	{
		dig = dig / 10;
		num++;
	}
	return (num);
}

uintmax_t		va_arg_u(va_list factor, t_pattern *tmp)
{
	if (tmp->j == 1)
		return (va_arg(factor, uintmax_t));
	if (tmp->l == 1)
		return (va_arg(factor, unsigned long));
	else if (tmp->ll == 1)
		return (va_arg(factor, unsigned long long));
	else if (tmp->h == 1)
		return ((unsigned short)va_arg(factor, unsigned int));
	else if (tmp->hh == 1)
		return ((unsigned char)va_arg(factor, unsigned int));
	else if (tmp->z == 1)
		return (va_arg(factor, size_t));
	else
		return (va_arg(factor, unsigned int));
}

void			print_u_help(t_pattern tmp, int *zero,
		int *space, uintmax_t digit)
{
	*space = 0;
	*zero = 0;
	if (tmp.precision > ft_countdigit_u(digit))
	{
		*zero = tmp.precision - ft_countdigit_u(digit);
		if (tmp.width > tmp.precision)
			*space = tmp.width - tmp.precision;
	}
	else if (tmp.width > ft_countdigit_u(digit))
		*space = tmp.width - ft_countdigit_u(digit);
}

void			ft_print_zero_u(t_pattern tmp)
{
	int					space;

	space = tmp.width;
	while (space-- > 0)
		ft_putchar(' ');
}

void			print_u(t_pattern tmp, va_list factor)
{
	uintmax_t			digit;
	int					space;
	int					zero;

	digit = va_arg_u(factor, &tmp);
	if (digit == 0 && tmp.point == 1 &&
			(tmp.precision == -1 || tmp.precision == 0))
	{
		ft_print_zero_u(tmp);
		return ;
	}
	print_u_help(tmp, &zero, &space, digit);
	if (tmp.minus != 1)
	{
		if (tmp.zero == 1 && tmp.point == 0)
			ft_putchar_help('0', &space);
		else
			ft_putchar_help(' ', &space);
	}
	while (zero-- > 0)
		ft_putchar('0');
	ft_putnbr_max_u(digit);
	if (tmp.minus == 1)
		ft_putchar_help(' ', &space);
}
