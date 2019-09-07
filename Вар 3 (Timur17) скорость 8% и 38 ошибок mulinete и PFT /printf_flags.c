/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <wtorwold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:53:09 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/16 20:22:22 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					ft_num(const char *format, int *i, va_list factor)
{
	int				at;

	at = 0;
	if (format[*i] == '*')
	{
		at = va_arg(factor, int);
		(*i)++;
		return (at);
	}
	else
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			at = at * 10 + (format[*i] - 48);
			(*i)++;
		}
	return (at);
}

void				put_cast(t_pattern *tmp, const char *format, int *i)
{
	if (format[*i] == 'z')
		tmp->z = 1;
	else if (format[*i] == 'L')
		tmp->m = 1;
	else if (format[*i] == 'j')
		tmp->j = 1;
	else if (format[*i] == 'h' && format[(*i) + 1] != 'h')
		tmp->h = 1;
	else if (format[*i] == 'h' && format[(*i) + 1] == 'h')
		tmp->hh = 1;
	else if (format[*i] == 'l' && format[(*i) + 1] != 'l')
		tmp->l = 1;
	else if (format[*i] == 'l' && format[(*i) + 1] == 'l')
		tmp->ll = 1;
	if (tmp->z == 1 || tmp->j == 1 || tmp->h == 1
			|| tmp->l == 1 || tmp->m == 1)
		(*i)++;
	else if (tmp->hh == 1 || tmp->ll == 1)
		(*i) = (*i) + 2;
}

void				addflag(t_pattern *tmp, char c)
{
	if (c == '+')
		tmp->plus = 1;
	else if (c == ' ')
		tmp->space = 1;
	else if (c == '-')
		tmp->minus = 1;
	else if (c == '#')
		tmp->hash = '1';
	else if (c == '0')
		tmp->zero = 1;
}

void				new_strc(t_strct *help)
{
	help->neg = 0;
	help->space = 0;
	help->zero = 0;
	help->f = 0;
}
