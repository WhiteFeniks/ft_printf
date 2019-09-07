/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:37:23 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/13 18:53:17 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_multiplex(t_info *info, va_list *ap)
{
	if (info->cur_f == 'U')
		info->flag = g_strjoin(ft_strdup(""), ft_strdup("l"), 1);
	if (info->cur_f == 'd' || info->cur_f == 'i')
		ft_process_s_int(info, ap);
	else if (info->cur_f == 'o')
		ft_process_o_b(info, ap, "01234567");
	else if (info->cur_f == 'x' || info->cur_f == 'X')
		ft_process_hex(info, ap);
	else if (info->cur_f == 'u' || info->cur_f == 'U')
		ft_process_u_int(info, ap);
	else if (info->cur_f == 'b')
		ft_process_o_b(info, ap, "01");
	else if (info->cur_f == 'c')
		ft_process_char(info, ap);
	else if (info->cur_f == 's')
		ft_process_str(info, ap);
	else if (info->cur_f == 'p')
		ft_process_pointer(info, ap);
	else if (info->cur_f == 'f' || info->cur_f == 'F')
		ft_process_real(info, ap);
	else if (info->cur_f == '\0')
		return ;
	else
		ft_process_chr(info, info->cur_f);
	(info->index)++;
}

void	ft_process(const char *format, t_info *info, va_list *ap)
{
	if (format[info->index] == '\0')
		return ;
	free(info->flag);
	ft_reset_info(info);
	ft_parse(format, info, ap);
	ft_multiplex(info, ap);
}

int		inc(char *s, t_info *info)
{
	info->index += ft_strlen(s) + 2;
	return (0);
}

void	ft_color(const char *format, t_info *info)
{
	if (!ft_strncmp(format + info->index, "{red}", 5))
		info->str = g_strjoin(info->str, "\033[0;31m", inc("red", info));
	else if (!ft_strncmp(format + info->index, "{bred}", 6))
		info->str = g_strjoin(info->str, "\033[1;31m", inc("bred", info));
	else if (!ft_strncmp(format + info->index, "{cyan}", 6))
		info->str = g_strjoin(info->str, "\033[0;36m", inc("cyan", info));
	else if (!ft_strncmp(format + info->index, "{bcyan}", 7))
		info->str = g_strjoin(info->str, "\033[1;36m", inc("bcyan", info));
	else if (!ft_strncmp(format + info->index, "{green}", 7))
		info->str = g_strjoin(info->str, "\033[0;32m", inc("green", info));
	else if (!ft_strncmp(format + info->index, "{blue}", 6))
		info->str = g_strjoin(info->str, "\033[0;34m", inc("blue", info));
	else if (!ft_strncmp(format + info->index, "{bblue}", 7))
		info->str = g_strjoin(info->str, "\033[1;34m", inc("bblue", info));
	else if (!ft_strncmp(format + info->index, "{magenta}", 9))
		info->str = g_strjoin(info->str, "\033[0;35m", inc("magenta", info));
	else if (!ft_strncmp(format + info->index, "{bmagenta}", 9))
		info->str = g_strjoin(info->str, "\033[1;35m", inc("bmagenta", info));
	else if (!ft_strncmp(format + info->index, "{yellow}", 8))
		info->str = g_strjoin(info->str, "\033[48;0;43m\033[38;2;30m",
		inc("yellow", info));
	else if (!ft_strncmp(format + info->index, "{oec}", 5))
		info->str = g_strjoin(info->str, "\033[0m", inc("oec", info));
	else
		info->str = g_charjoin(info->str, format[(info->index)++]);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_info	info;

	ft_init_info(&info);
	va_start(ap, format);
	while (format[info.index])
	{
		if (format[info.index] == '%')
		{
			(info.index)++;
			ft_process(format, &info, &ap);
		}
		else if (format[info.index] == '{')
			ft_color(format, &info);
		else
			info.str = g_charjoin(info.str, format[(info.index)++]);
	}
	va_end(ap);
	info.nb_p += ft_strlen(info.str);
	ft_putstr(info.str);
	free(info.flag);
	free(info.str);
	return (info.nb_p);
}
