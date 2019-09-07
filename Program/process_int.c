/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 04:17:02 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/21 00:54:10 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_s_int(t_info *info, va_list *ap)
{
	char	*i;
	char	*base;

	base = "0123456789";
	if (info->prc >= 0)
		info->fill = ' ';
	if (info->flag == NULL)
		return (ft_s_itobase(va_arg(*ap, int), base));
	if (ft_strncmp(info->flag, "ll", 2) == 0)
		i = ft_s_itobase(va_arg(*ap, LL), base);
	else if (ft_strncmp(info->flag, "l", 1) == 0)
		i = ft_s_itobase(va_arg(*ap, long), base);
	else if (ft_strncmp(info->flag, "hh", 2) == 0)
		i = ft_s_itobase((char)va_arg(*ap, int), base);
	else if (ft_strncmp(info->flag, "h", 1) == 0)
		i = ft_s_itobase((short)va_arg(*ap, int), base);
	else if (ft_strncmp(info->flag, "j", 1) == 0)
		i = ft_s_itobase(va_arg(*ap, intmax_t), base);
	else if (ft_strncmp(info->flag, "z", 1) == 0)
		i = ft_s_itobase(va_arg(*ap, size_t), base);
	else
		i = ft_s_itobase(va_arg(*ap, int), base);
	return (i);
}

char	*ft_get_u_int(t_info *info, va_list *ap)
{
	char	*i;
	char	*base;

	base = "0123456789";
	if (info->prc > 0)
		info->fill = ' ';
	if (info->flag == NULL)
		return (ft_itobase(va_arg(*ap, unsigned int), base));
	if (ft_strncmp(info->flag, "ll", 2) == 0)
		i = ft_itobase(va_arg(*ap, ULL), base);
	else if (ft_strncmp(info->flag, "l", 1) == 0)
		i = ft_itobase(va_arg(*ap, unsigned long), base);
	else if (ft_strncmp(info->flag, "hh", 2) == 0)
		i = ft_itobase((unsigned char)va_arg(*ap, unsigned int), base);
	else if (ft_strncmp(info->flag, "h", 1) == 0)
		i = ft_itobase((unsigned short)va_arg(*ap, unsigned int), base);
	else if (ft_strncmp(info->flag, "j", 1) == 0)
		i = ft_itobase(va_arg(*ap, uintmax_t), base);
	else if (ft_strncmp(info->flag, "z", 1) == 0)
		i = ft_itobase(va_arg(*ap, size_t), base);
	else
		i = ft_itobase(va_arg(*ap, unsigned int), base);
	return (i);
}

void	check_str(char **str, char **pr, t_info *info)
{
	if (!ft_strcmp(*str, "0") && info->prc == 0)
	{
		free(*str);
		*str = ft_strdup("");
	}
	*pr = info->sign && (*str)[0] != '-' ? ft_strdup("+") : ft_strdup("");
	if ((*str)[0] == '-')
	{
		free(*pr);
		*pr = g_strjoin(ft_strdup(""), *str + 1, 0);
		free(*str);
		*str = *pr;
		*pr = ft_strdup("-");
	}
	else
		*pr = info->space ? g_strjoin(ft_strdup(" "), *pr, 1) : *pr;
}

void	ft_process_s_int(t_info *info, va_list *ap)
{
	char	*str;
	char	*tmp;
	int		len;
	char	*pr;

	str = ft_get_s_int(info, ap);
	check_str(&str, &pr, info);
	len = info->fields - ft_strlen(str) - ft_strlen(pr)
	- ft_val(info->prc - ft_strlen(str));
	tmp = len > 0 ? str_gen(info->fill, len) : ft_strdup("");
	ft_concat_str(&str, &pr, &tmp, info);
	info->str = g_strjoin(info->str, str, 1);
}

void	ft_process_u_int(t_info *info, va_list *ap)
{
	char	*str;
	char	*tmp;
	int		len;
	char	*pr;

	str = ft_get_u_int(info, ap);
	if (!ft_strcmp(str, "0") && info->prc == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	pr = ft_strdup("");
	len = info->fields - ft_strlen(str) - ft_strlen(pr)
	- ft_val(info->prc - ft_strlen(str));
	tmp = len > 0 ? str_gen(info->fill, len) : ft_strdup("");
	ft_concat_str(&str, &pr, &tmp, info);
	info->str = g_strjoin(info->str, str, 1);
}
