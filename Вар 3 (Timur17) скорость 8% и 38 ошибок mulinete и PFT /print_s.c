/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:28:46 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/16 20:12:29 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*print_s_help(t_pattern tmp, va_list factor)
{
	char		*str;
	char		*leak;
	char		*s;
	int			len;

	s = va_arg(factor, char*);
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (tmp.precision < len && tmp.precision >= 0)
	{
		str = ft_strsub(s, 0, tmp.precision);
	}
	else
	{
		str = ft_memalloc(1);
		leak = ft_strjoin(str, s);
		free(str);
		str = leak;
	}
	return (str);
}

char		*prin_s_null(t_pattern tmp)
{
	int			len;
	char		*str;
	char		*leak;

	str = ft_strjoin("", "(null)");
	len = 6;
	if (tmp.precision < len && tmp.precision >= 0)
	{
		leak = ft_strsub(str, 0, tmp.precision);
		free(str);
		str = leak;
	}
	return (str);
}

void		print_s(t_pattern tmp, va_list factor)
{
	int			len;
	char		*str;

	str = print_s_help(tmp, factor);
	if (str == NULL)
		str = prin_s_null(tmp);
	if (tmp.minus == 1)
		ft_putstr(str);
	len = (int)ft_strlen(str);
	if (tmp.width > len)
	{
		len = tmp.width - len;
		if (tmp.zero == 1 && tmp.minus != 1)
		{
			while (len-- > 0)
				ft_putchar('0');
		}
		else
			while (len-- > 0)
				ft_putchar(' ');
	}
	if (tmp.minus == 0)
		ft_putstr(str);
	if (str != NULL)
		free(str);
}
