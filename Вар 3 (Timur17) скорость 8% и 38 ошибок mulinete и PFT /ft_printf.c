/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:53:09 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/16 20:04:02 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					print(t_pattern tmp, va_list factor)
{
	char				c;

	if (tmp.type == 'd' || tmp.type == 'i' || tmp.type == 'D')
		print_int(tmp, factor);
	else if (tmp.type == 'u' || tmp.type == 'U')
		print_u(tmp, factor);
	else if (tmp.type == 'c')
	{
		c = (va_arg(factor, int));
		print_c(tmp, c);
	}
	else if (tmp.type == 's')
		print_s(tmp, factor);
	else if (tmp.type == 'f' && tmp.m)
		ft_print_f(tmp, va_arg(factor, long double));
	else if (tmp.type == 'f')
		ft_print_f(tmp, va_arg(factor, double));
	else if (tmp.type == 'x' || tmp.type == 'p'
	|| tmp.type == 'X' || tmp.type == 'o')
		ft_print_p(tmp, va_arg(factor, uintmax_t));
	return (0);
}

int					ft_search(char c, t_pattern tmp, va_list factor)
{
	int					count;
	static int			add = 0;

	count = 0;
	if (type(c) != 0)
	{
		if (add == 0 && c == 'U')
		{
			add++;
			return (0);
		}
		tmp.type = c;
		print(tmp, factor);
		count++;
	}
	else if (ft_strindex("*0123456789.;# '+-hlLzj", c) < 0 && c != '\0')
	{
		tmp.type = 'c';
		print_c(tmp, c);
		count++;
	}
	return (count);
}

int					ft_parse(const char *format,
		int *i, t_pattern *tmp, va_list factor)
{
	while (ft_flag(format[*i]) != 0)
		addflag(tmp, format[(*i)++]);
	if ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '*')
		tmp->width = ft_num(format, i, factor);
	if (format[*i] == '.')
	{
		tmp->point = 1;
		(*i)++;
		tmp->precision = ft_num(format, i, factor);
	}
	if (ft_cast(format[*i]) != 0)
		put_cast(tmp, format, i);
	if (format[*i] == 'U')
		tmp->j = 1;
	return (0);
}

int					ft_printf(const char *format, ...)
{
	int						i;
	t_pattern				tmp;
	va_list					factor;

	i = 0;
	g_result = 0;
	va_start(factor, format);
	while (format[i] != 0)
	{
		if (format[i] == '%' && (i = i + 1) != -1)
		{
			new_pattern(&tmp);
			while (!ft_search(format[i], tmp, factor))
			{
				ft_parse(format, &i, &tmp, factor);
				if (format[i] == '\0')
					return (g_result);
			}
			i++;
		}
		else
			ft_putchar(format[i++]);
	}
	va_end(factor);
	return (g_result);
}
