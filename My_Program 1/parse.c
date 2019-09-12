/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:16:46 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/13 19:03:12 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	extract_flags(const char *format, t_info *info)
{
	while (format[info->index] && char_in(format[info->index],
		"0# -+"))
	{
		if (format[info->index] == '#' && !(info->diaz))
			info->diaz = 1;
		if (format[info->index] == '0' && !(info->minus) && info->prc == -2)
			info->fill = '0';
		if (format[info->index] == '-' && !(info->minus))
		{
			info->minus = 1;
			info->fill = ' ';
		}
		if (format[info->index] == ' ' && !(info->sign))
			info->space = 1;
		if (format[info->index] == '+' && !(info->sign))
		{
			info->sign = 1;
			info->space = 0;
		}
		(info->index)++;
	}
}

void	extract_prc(const char *format, t_info *info, va_list *ap)
{
	if (format[info->index] == '.')
	{
		while (format[info->index] == '.')
			(info->index)++;
		if (ft_isdigit(format[info->index]) || format[info->index] == '-')
		{
			info->prc = ft_atoi(format + info->index);
			info->index += ft_nb_digit(info->prc);
		}
		else if (format[info->index] == '*')
		{
			info->prc = va_arg(*ap, int);
			info->prc = info->prc < 0 ? -2 : info->prc;
			(info->index)++;
		}
		else
			info->prc = -1;
	}
	else
	{
		info->prc = -2;
		if (!char_in(format[info->index], "diuUoxXpbscfF"))
			(info->index)++;
	}
}

void	extract_field_prc(const char *format, t_info *info, va_list *ap)
{
	while (format[info->index] && char_in(format[info->index], ".*1234567890"))
	{
		if (format[info->index] == '*')
		{
			info->fields = va_arg(*ap, int);
			if (info->fields < 0)
			{
				info->fields = -info->fields;
				info->minus = 1;
				info->fill = ' ';
			}
			(info->index)++;
		}
		else if (ft_isdigit(format[info->index]))
		{
			info->fields = ft_atoi(format + info->index);
			info->index += ft_nb_digit(info->fields) - 1;
		}
		extract_prc(format, info, ap);
	}
}

void	extract_conversion(const char *format, t_info *info)
{
	while (format[info->index] && char_in(format[info->index], "lhLjz"))
	{
		if (!ft_strncmp(format + info->index, "hh", 2))
			info->flag = g_strjoin(ft_strdup(""), ft_strdup("hh"), 1);
		else if (!ft_strncmp(format + info->index, "ll", 2)
			&& (!info->flag || 'l' >= info->flag[0]))
			info->flag = g_strjoin(ft_strdup(""), ft_strdup("ll"), 1);
		else if (!ft_strncmp(format + info->index, "h", 1)
			&& (!info->flag || 'h' >= info->flag[0]))
			info->flag = g_strjoin(ft_strdup(""), ft_strdup("h"), 1);
		else if (!ft_strncmp(format + info->index, "l", 1)
			&& (!info->flag || 'l' > info->flag[0]))
			info->flag = g_strjoin(ft_strdup(""), ft_strdup("l"), 1);
		else if (!ft_strncmp(format + info->index, "L", 1)
			&& (!info->flag || 'l' > info->flag[0]))
			info->flag = g_strjoin(ft_strdup(""), ft_strdup("L"), 1);
		else if (!ft_strncmp(format + info->index, "j", 1)
			&& (!info->flag || 'j' > info->flag[0]))
			info->flag = g_strjoin(ft_strdup(""), ft_strdup("j"), 1);
		else if (!ft_strncmp(format + info->index, "z", 1))
			info->flag = g_strjoin(ft_strdup(""), ft_strdup("z"), 1);
		info->index += info->flag ? ft_strlen(info->flag) : 1;
	}
}

void	ft_parse(const char *format, t_info *info, va_list *ap)
{
	extract_flags(format, info);
	extract_field_prc(format, info, ap);
	extract_conversion(format, info);
	extract_flags(format, info);
	info->cur_f = format[info->index];
	while (format[info->index] == '.')
		(info->index)++;
	if (info->prc == -1)
		info->prc = 0;
}
