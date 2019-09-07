/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_decimal_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:31:27 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/22 15:31:31 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_decimal_str(t_saver *saver, va_list arg)
{
	char				*str;
	char				*final;
	long long			nbr;
	int					minus;

	minus = 0;
	nbr = get_number_arg(saver, arg);
	if (nbr < 0 && (minus = 1))
		nbr *= -1;
	str = ft_utoa_base((unsigned long long)nbr, 10);
	if (minus == 1)
		final = ft_join("-", str, SECOND);
	else
		final = str;
	if (nbr == 0 && saver->precision == 0)
	{
		free(final);
		final = ft_strdup("");
	}
	final = add_precision(saver, final);
	final = add_flags(saver, final);
	final = add_min_width(saver, final);
	return (final);
}

char		*get_uns_decimal_str(t_saver *saver, va_list arg)
{
	char				*final;
	unsigned long long	unsigned_nbr;

	unsigned_nbr = get_unsigned_number_arg(saver, arg);
	final = ft_utoa_base(unsigned_nbr, 10);
	if (unsigned_nbr == 0 && saver->precision == 0)
	{
		free(final);
		final = ft_strdup("");
	}
	final = add_precision(saver, final);
	final = add_min_width(saver, final);
	return (final);
}
