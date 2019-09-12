/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:37:30 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/22 15:37:32 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_width(char c, t_saver *saver)
{
	int		tmp;

	if (saver->width > 1)
	{
		tmp = saver->width - 1;
		if (saver->minus_null == '-')
			ft_put_char(c);
		while (tmp > 0)
		{
			if (saver->minus_null == '0')
				ft_put_char('0');
			else
				ft_put_char(' ');
			tmp--;
		}
		if (saver->minus_null != '-')
			ft_put_char(c);
	}
	else
		ft_put_char(c);
}

void	print_char(t_saver *saver, va_list arg)
{
	char	c;

	if (saver->specifier == 'c' && saver->size == L)
		c = (char)va_arg(arg, wint_t);
	else if (saver->specifier == 'c')
		c = va_arg(arg, int);
	else
		c = saver->specifier;
	char_width(c, saver);
}
