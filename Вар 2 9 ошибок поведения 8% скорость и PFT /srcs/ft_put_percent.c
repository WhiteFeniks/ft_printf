/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:12:16 by huller            #+#    #+#             */
/*   Updated: 2019/08/05 21:57:28 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reader(t_rd **read, va_list *ap, const char *format, t_out *out)
{
	(*read)->zero = 0;
	format[(*read)->smb_cnt] == '%' ? ++(*read)->smb_cnt : 0;
	ft_chck_flags(read, format);
	ft_chck_wdth(read, format, &ap);
	ft_chck_precision(read, format, &ap);
	ft_chck_size(read, format);
	ft_mod(read, format, &ap, out);
	if (((*read)->mod_smb == 'd' || (*read)->mod_smb == 'i' ||
	(*read)->mod_smb == 's' || (*read)->mod_smb == 'u' ||
	(*read)->mod_smb == 'p') && !(*read)->prs)
		(*read)->kostil = 3;
	else if (((*read)->mod_smb == 'd' || (*read)->mod_smb == 'i' ||
	(*read)->mod_smb == 's' || (*read)->mod_smb == 'u' ||
	(*read)->mod_smb == 'p') && (*read)->prs == 6 &&
	(*read)->kostil != 1)
		(*read)->prs = 0;
}

int		ft_pt_frst(const char *format, t_out *output, t_rd **rd)
{
	t_pft	t;

	t.i = 0;
	t.b = -1;
	t.tmp = (*rd)->smb_cnt;
	while (format[(*rd)->smb_cnt] && format[(*rd)->smb_cnt] != '%')
	{
		(*rd)->smb_cnt++;
		t.i++;
	}
	if (!(t.res = (char *)malloc(sizeof(char) * (t.i + 1))))
		return (0);
	t.res[t.i] = '\0';
	t.tmp--;
	while (++t.b < t.i)
		t.res[t.b] = format[++t.tmp];
	if (!(*output).buf)
		(*output).buf = ft_strnew(0);
	t.tmp2 = (*output).buf;
	(*output).buf = ft_bufjoin((*output).buf, t.res, (*output).cnt, t.i);
	free((void *)t.res);
	(*output).cnt += t.i;
	t.tmp2 ? free((void *)t.tmp2) : 0;
	return (SUCCESS);
}

void	ft_check_2(const char *format, t_rd **read, t_check *c)
{
	c->i = 0;
	c->b = -1;
	while (format[(*read)->smb_cnt] == 'l' || format[(*read)->smb_cnt] == 'h' ||
	format[(*read)->smb_cnt] == 'j' || format[(*read)->smb_cnt] == 'z' ||
	format[(*read)->smb_cnt] == 'L' || format[(*read)->smb_cnt] == 't')
		++(*read)->smb_cnt;
	c->tmp = (*read)->smb_cnt;
}

int		chck_nthng(const char *format, t_out *output, t_rd **read)
{
	t_check		c;

	ft_check_2(format, read, &c);
	if ((format[(*read)->smb_cnt] >= 'A' && format[(*read)->smb_cnt] <= 'Z') ||
	(format[(*read)->smb_cnt] >= 'a' && format[(*read)->smb_cnt] <= 'z'))
	{
		while (format[(*read)->smb_cnt] && format[(*read)->smb_cnt] != '%')
		{
			(*read)->smb_cnt++;
			c.i++;
		}
		if (!(c.res = (char *)malloc(sizeof(char) * (c.i + 1))))
			return (0);
		c.res[c.i] = '\0';
		c.tmp--;
		while (++c.b < c.i)
			c.res[c.b] = format[++c.tmp];
		c.tmp2 = (*output).buf;
		(*output).buf = ft_bufjoin((*output).buf, c.res, (*output).cnt, c.i);
		free((void *)c.res);
		c.tmp2 ? free((void *)c.tmp2) : 0;
		--(*read)->smb_cnt;
		(*output).cnt += c.i;
	}
	return (SUCCESS);
}

void	ft_put_percent(t_rd **read)
{
	(*read)->mod = (char *)malloc(sizeof(char) * 2);
	(*read)->mod[0] = '%';
	(*read)->mod[1] = '\0';
	(*read)->mod_smb = '%';
}
