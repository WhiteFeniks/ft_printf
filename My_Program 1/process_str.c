/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:27:15 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/14 10:35:06 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_char(t_info *info, va_list *ap)
{
	char	c;
	char	*tmp;

	c = va_arg(*ap, int);
	if (info->fields - 1 > 0)
		tmp = str_gen(info->fill, info->fields - 1);
	else
		tmp = NULL;
	info->nb_p += ft_strlen(info->str) + 1;
	info->nb_p += tmp == NULL ? 0 : ft_strlen(tmp);
	write(1, info->str, ft_strlen(info->str));
	if (info->minus == 0)
		ft_putstr(tmp);
	write(1, &c, 1);
	free(info->str);
	info->str = ft_strdup("");
	if (info->minus)
		ft_putstr(tmp);
	free(tmp);
}

void	ft_process_chr(t_info *info, char c)
{
	char	*tmp;

	if (info->fields - 1 > 0)
		tmp = str_gen(info->fill, info->fields - 1);
	else
		tmp = NULL;
	info->nb_p += ft_strlen(info->str) + 1;
	info->nb_p += tmp == NULL ? 0 : ft_strlen(tmp);
	write(1, info->str, ft_strlen(info->str));
	if (info->minus == 0)
		ft_putstr(tmp);
	write(1, &c, 1);
	free(info->str);
	info->str = ft_strdup("");
	if (info->minus)
		ft_putstr(tmp);
	free(tmp);
}

void	ft_process_str(t_info *info, va_list *ap)
{
	char	*str;
	char	*tmp;
	int		len;
	char	*t;

	str = va_arg(*ap, char*);
	str = str == NULL ? ft_strdup("(null)") : ft_strdup(str);
	info->prc = info->prc == -2 ? ft_strlen(str) : info->prc;
	t = str;
	str = ft_strsub(str, 0, info->prc);
	free(t);
	len = info->fields - ft_strlen(str);
	tmp = len > 0 ? str_gen(info->fill, len) : NULL;
	if (tmp && info->minus)
	{
		str = g_strjoin(str, tmp, 1);
	}
	else if (tmp && info->minus == 0)
	{
		tmp = g_strjoin(tmp, str, 1);
		str = tmp;
	}
	info->str = g_strjoin(info->str, str, 1);
}

void	ft_process_pointer(t_info *info, va_list *ap)
{
	char	*str;
	char	*tmp;
	int		len;
	char	*pr;

	str = ft_itobase((ULL)va_arg(*ap, void*), "0123456789abcdef");
	if (info->prc == 0 && ft_strcmp(str, "0") == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	pr = ft_strdup("0x");
	info->fill = info->prc > 0 ? ' ' : info->fill;
	len = info->fields - ft_strlen(str) - 2
	- ft_val(info->prc - ft_strlen(str));
	tmp = len > 0 ? str_gen(info->fill, len) : ft_strdup("");
	ft_concat_str(&str, &pr, &tmp, info);
	info->str = g_strjoin(info->str, str, 1);
}
