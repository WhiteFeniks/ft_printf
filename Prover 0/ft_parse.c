/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:12:44 by mbodak            #+#    #+#             */
/*   Updated: 2017/02/21 19:13:12 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		parse_flags(const char *format, size_t i, t_saver *saver)
{
	while (is_flag(format, i))
	{
		if (format[i] == '#')
			saver->hash = '#';
		else if (format[i] == '-' || format[i] == '0')
		{
			if (format[i] == '0' && saver->minus_null != '-')
				saver->minus_null = format[i];
			else if (format[i] == '-')
				saver->minus_null = format[i];
		}
		else if (format[i] == '+' || format[i] == ' ')
		{
			if (format[i] == ' ' && saver->plus_space != '+')
				saver->plus_space = format[i];
			else if (format[i] == '+')
				saver->plus_space = format[i];
		}
		i++;
	}
	return (i);
}

size_t		parse_width(const char *format, size_t i, t_saver *saver, va_list a)
{
	if (ft_isdigit(format[i]))
	{
		saver->width = ft_atoi(format + i);
		while (ft_isdigit(format[i]))
			i++;
	}
	else if (format[i] == '*')
	{
		saver->width = va_arg(a, int);
		if (saver->width < 0)
		{
			saver->width *= -1;
			saver->minus_null = '-';
		}
		i++;
	}
	return (i);
}

size_t		parse_prec(const char *format, size_t i, t_saver *saver, va_list a)
{
	if (format[i] == '.')
	{
		i++;
		saver->precision = 0;
		if (ft_isdigit(format[i]))
		{
			saver->precision = ft_atoi(format + i);
			while (ft_isdigit(format[i]))
				i++;
		}
		else if (format[i] == '*')
		{
			saver->precision = va_arg(a, int);
			i++;
		}
	}
	return (i);
}

size_t		parse_size(const char *format, size_t i, t_saver *saver)
{
	t_size	size;

	while (is_size(format, i))
	{
		size = get_size(format, i);
		if (saver->size < size)
			saver->size = size;
		i += is_size(format, i);
	}
	return (i);
}

size_t		parse_specif(const char *format, size_t i, t_saver *saver)
{
	char c;

	c = format[i];
	if (c == 'D' || c == 'O' || c == 'U' || c == 'C' || c == 'S')
	{
		c = (char)ft_tolower(c);
		saver->size = L;
	}
	saver->specifier = c;
	return (i);
}
