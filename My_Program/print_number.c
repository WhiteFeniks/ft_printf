/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:30:59 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/22 15:31:02 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long				get_number_arg(t_saver *saver, va_list arg)
{
	long long int	nbr;

	if (saver->size == HH)
		nbr = (signed char)va_arg(arg, int);
	else if (saver->size == H)
		nbr = (short)va_arg(arg, int);
	else if (saver->size == L)
		nbr = (long)va_arg(arg, long int);
	else if (saver->size == LL)
		nbr = (long long)va_arg(arg, long long int);
	else if (saver->size == J)
		nbr = (intmax_t)va_arg(arg, intmax_t);
	else if (saver->size == Z)
		nbr = (ssize_t)va_arg(arg, ssize_t);
	else
		nbr = (int)va_arg(arg, int);
	return (nbr);
}

unsigned long long		get_unsigned_number_arg(t_saver *saver, va_list arg)
{
	unsigned long long int	nbr;

	if (saver->size == HH)
		nbr = (unsigned char)va_arg(arg, unsigned int);
	else if (saver->size == H)
		nbr = (unsigned short)va_arg(arg, unsigned int);
	else if (saver->size == L)
		nbr = (unsigned long)va_arg(arg, unsigned long int);
	else if (saver->size == LL)
		nbr = (unsigned long long)va_arg(arg, unsigned long long int);
	else if (saver->size == J)
		nbr = (uintmax_t)va_arg(arg, uintmax_t);
	else if (saver->size == Z)
		nbr = (size_t)va_arg(arg, size_t);
	else
		nbr = (unsigned int)va_arg(arg, unsigned int);
	return (nbr);
}

void					print_number(t_saver *saver, va_list arg)
{
	char	*str;

	if (saver->specifier == 'd' || saver->specifier == 'i')
		str = get_decimal_str(saver, arg);
	else if (saver->specifier == 'u')
		str = get_uns_decimal_str(saver, arg);
	else if (saver->specifier == 'o')
		str = get_octal_str(saver, arg);
	else if (saver->specifier == 'x' || saver->specifier == 'X')
		str = get_hex_str(saver, arg);
	else if (saver->specifier == 'b')
		str = get_binary_str(saver, arg);
	else
		str = ft_strdup("");
	ft_put_string(str);
	free(str);
}
