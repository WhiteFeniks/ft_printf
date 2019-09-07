/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:22:15 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/21 00:36:56 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_o_b(t_info *info, va_list *ap, char *base)
{
	char	*ob;

	if (info->prc >= 0)
		info->fill = ' ';
	if (info->flag == NULL)
		return (ft_itobase(va_arg(*ap, unsigned int), base));
	if (ft_strncmp(info->flag, "ll", 2) == 0)
		ob = ft_itobase(va_arg(*ap, ULL), base);
	else if (ft_strncmp(info->flag, "l", 1) == 0)
		ob = ft_itobase(va_arg(*ap, unsigned long), base);
	else if (ft_strncmp(info->flag, "hh", 2) == 0)
		ob = ft_itobase((unsigned char)va_arg(*ap, unsigned int), base);
	else if (ft_strncmp(info->flag, "h", 1) == 0)
		ob = ft_itobase((unsigned short)va_arg(*ap, unsigned int), base);
	else if (ft_strncmp(info->flag, "j", 1) == 0)
		ob = ft_itobase(va_arg(*ap, uintmax_t), base);
	else if (ft_strncmp(info->flag, "z", 1) == 0)
		ob = ft_itobase(va_arg(*ap, size_t), base);
	else
		ob = ft_itobase(va_arg(*ap, unsigned int), base);
	return (ob);
}

void	ft_process_o_b(t_info *info, va_list *ap, char *base)
{
	char	*str;
	char	*tmp;
	int		len;
	char	*pr;
	int		e;

	str = ft_get_o_b(info, ap, base);
	if (info->diaz && ft_strcmp(str, "0"))
		(info->prc)--;
	e = !ft_strcmp(str, "0") && info->prc == 0 && !info->diaz;
	pr = info->diaz && ft_strcmp(str, "0") ? ft_strdup("0") : ft_strdup("");
	len = info->fields - ft_strlen(str) + e - ft_strlen(pr)
	- ft_val(info->prc - ft_strlen(str));
	tmp = len > 0 ? str_gen(info->fill, len) : ft_strdup("");
	ft_concat_str(&str, &pr, &tmp, info);
	info->str = g_strjoin(info->str, e ? str_gen(info->fill, len) : str, 1);
}

char	*ft_get_hex(t_info *info, va_list *ap)
{
	char	*h;
	char	*f;

	if (info->prc >= 0)
		info->fill = ' ';
	f = info->cur_f == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	if (info->flag == NULL)
		return (ft_itobase(va_arg(*ap, unsigned int), f));
	if (ft_strncmp(info->flag, "ll", 2) == 0)
		h = ft_itobase(va_arg(*ap, ULL), f);
	else if (ft_strncmp(info->flag, "l", 1) == 0)
		h = ft_itobase(va_arg(*ap, unsigned long), f);
	else if (ft_strncmp(info->flag, "hh", 2) == 0)
		h = ft_itobase((unsigned char)va_arg(*ap, unsigned int), f);
	else if (ft_strncmp(info->flag, "h", 1) == 0)
		h = ft_itobase((unsigned short)va_arg(*ap, unsigned int), f);
	else if (ft_strncmp(info->flag, "j", 1) == 0)
		h = ft_itobase(va_arg(*ap, uintmax_t), f);
	else if (ft_strncmp(info->flag, "z", 1) == 0)
		h = ft_itobase(va_arg(*ap, size_t), f);
	else
		h = ft_itobase(va_arg(*ap, unsigned int), f);
	return (h);
}

void	ft_process_hex(t_info *info, va_list *ap)
{
	char	*str;
	char	*tmp;
	int		len;
	char	*pr;

	str = ft_get_hex(info, ap);
	if (!ft_strcmp(str, "0") && info->prc == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	pr = info->diaz && str[0] != '\0' && str[0] != '0'
	? g_charjoin(ft_strdup("0"), info->cur_f) : ft_strdup("");
	len = info->fields - ft_strlen(str) - ft_strlen(pr)
	- ft_val(info->prc - ft_strlen(str));
	tmp = len > 0 ? str_gen(info->fill, len) : ft_strdup("");
	ft_concat_str(&str, &pr, &tmp, info);
	info->str = g_strjoin(info->str, str, 1);
}
