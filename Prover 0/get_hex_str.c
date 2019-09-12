/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:33:50 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/22 15:33:53 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_hex_str(t_saver *saver, va_list arg)
{
	char				*str;
	char				*final;
	unsigned long long	unsigned_nbr;

	unsigned_nbr = get_unsigned_number_arg(saver, arg);
	str = ft_utoa_base(unsigned_nbr, 16);
	if (saver->specifier == 'x')
		str = ft_lower(str);
	if (saver->hash == '#' && str[0] != '0')
	{
		if (saver->specifier == 'x')
			final = ft_join("0x", str, SECOND);
		else if (saver->specifier == 'X')
			final = ft_join("0X", str, SECOND);
	}
	else
		final = str;
	if (unsigned_nbr == 0 && saver->precision == 0)
	{
		free(final);
		final = ft_strdup("");
	}
	final = add_precision(saver, final);
	final = add_min_width(saver, final);
	return (final);
}
