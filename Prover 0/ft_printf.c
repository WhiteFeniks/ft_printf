/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:51:40 by mbodak            #+#    #+#             */
/*   Updated: 2017/02/07 17:51:43 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_saver		*create_struct(void)
{
	t_saver		*saver;

	saver = (t_saver *)malloc(sizeof(t_saver));
	saver->hash = '\0';
	saver->minus_null = '\0';
	saver->plus_space = '\0';
	saver->width = 0;
	saver->precision = -1;
	saver->size = DEF;
	saver->specifier = '\0';
	return (saver);
}

size_t		parse_it(const char *format, size_t i, t_saver *saver, va_list a)
{
	size_t	tmp;

	tmp = 0;
	while (format[i] && i > tmp)
	{
		tmp = i;
		i = parse_flags(format, i, saver);
		i = parse_width(format, i, saver, a);
		i = parse_prec(format, i, saver, a);
		i = parse_size(format, i, saver);
	}
	if (format[i])
		i = parse_specif(format, i, saver);
	return (i);
}

int			arg_print(t_saver *saver, va_list arg)
{
	if (ft_strchr("bdiouxX", saver->specifier))
		print_number(saver, arg);
	else if (saver->specifier == 'p')
		print_pointer(saver, arg);
	else if (saver->specifier == 's')
		print_string(saver, arg);
	else
		print_char(saver, arg);
	return (1);
}

int			run_format(const char *format, va_list arg)
{
	size_t		i;
	t_saver		*saver;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			saver = create_struct();
			i = parse_it(format, i + 1, saver, arg);
			if (format[i] == '\0')
				break ;
			arg_print(saver, arg);
			free(saver);
		}
		else
			ft_write(1, format + i, 1);
		i++;
	}
	return (0);
}

int			ft_printf(const char *restrict format, ...)
{
	int			count;
	va_list		arg;

	if (!format)
		return (-1);
	va_start(arg, format);
	run_format(format, arg);
	va_end(arg);
	count = (int)g_count;
	g_count = 0;
	return (count);
}
