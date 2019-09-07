/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:53:09 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/16 20:12:07 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				print_int_help(t_pattern tmp,
		intmax_t *digit, t_strct *help)
{
	if (*digit < 0)
		help->neg = 1;
	if (help->neg == 1 || tmp.plus == 1 || tmp.space == 1)
		help->f = 1;
	if (tmp.precision > ft_countdigit(*digit))
	{
		help->zero = tmp.precision - ft_countdigit(*digit);
		if (tmp.width > tmp.precision)
			help->space = tmp.width - tmp.precision - help->f;
	}
	else if (tmp.width > ft_countdigit(*digit))
		help->space = tmp.width - ft_countdigit(*digit) - help->f;
	help->f = 0;
}

void				ft_print_zero(t_pattern tmp, t_strct *help)
{
	if (tmp.plus == 1 || tmp.space == 1)
		help->f = 1;
	help->space = tmp.width - help->f;
	if (tmp.space == 1 && tmp.plus == 0)
		ft_putchar(' ');
	if (tmp.plus == 1 && tmp.minus == 1)
		ft_putchar('+');
	while (help->space-- > 0)
		ft_putchar(' ');
	if (tmp.plus == 1 && tmp.minus == 0)
		ft_putchar('+');
}

void				ft_positive_num(t_pattern tmp,
		t_strct *help, intmax_t *digit)
{
	if (tmp.zero == 1 && tmp.precision == -1)
	{
		if (help->neg == 1)
		{
			*digit = *digit * (-1);
			ft_putchar('-');
			help->neg = 0;
			help->f = 1;
		}
		if (help->f != 1 && tmp.plus == 1)
		{
			ft_putchar('+');
			help->f++;
		}
		while (help->space-- > 0)
			ft_putchar('0');
	}
	else
		while (help->space-- > 0)
			if (tmp.zero == 1 && tmp.precision == -1)
				ft_putchar('0');
			else
				ft_putchar(' ');
}

void				partof_print_int(t_pattern tmp,
		t_strct help, intmax_t digit)
{
	if (tmp.plus == 1 && digit >= 0 && help.f != 1)
		ft_putchar('+');
	while (help.zero-- > 0)
		ft_putchar('0');
	ft_putnbr_max(digit, help.f);
	if (tmp.minus == 1)
		while (help.space-- > 0)
			ft_putchar(' ');
}

void				print_int(t_pattern tmp, va_list factor)
{
	intmax_t			digit;
	t_strct				help;

	new_strc(&help);
	digit = va_arg_help(factor, &tmp);
	if (digit == 0 && tmp.point == 1 &&
			(tmp.precision == -1 || tmp.precision == 0))
	{
		ft_print_zero(tmp, &help);
		return ;
	}
	print_int_help(tmp, &digit, &help);
	if (tmp.space == 1 && digit >= 0 && tmp.plus == 0)
		ft_putchar(' ');
	if (tmp.minus != 1)
		ft_positive_num(tmp, &help, &digit);
	if (help.neg == 1 && tmp.precision > ft_countdigit(digit))
	{
		digit = digit * (-1);
		ft_putchar('-');
		help.f = 1;
	}
	partof_print_int(tmp, help, digit);
}
