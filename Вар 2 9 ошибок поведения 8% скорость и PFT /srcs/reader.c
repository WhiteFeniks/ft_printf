/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:24:05 by huller            #+#    #+#             */
/*   Updated: 2019/06/18 17:24:07 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mod(t_rd **read, const char *format, va_list **ap, t_out *out)
{
	(*read)->mod = NULL;
	(*read)->mod2 = NULL;
	(*read)->mod_smb = 0;
	if (format[(*read)->smb_cnt] == '*')
		(*read)->smb_cnt++;
	if (format[(*read)->smb_cnt] == 's' || format[(*read)->smb_cnt] == 'r')
		format[(*read)->smb_cnt] == 's' ? chck_sr(read, ap, 1) :
		chck_sr(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'd' || format[(*read)->smb_cnt] == 'i')
		format[(*read)->smb_cnt] == 'd' ? chck_di(read, ap, 1) :
		chck_di(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'f' || format[(*read)->smb_cnt] == 'F')
		format[(*read)->smb_cnt] == 'f' ? chck_f(read, ap, 1) :
		chck_f(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'e' || format[(*read)->smb_cnt] == 'E')
		format[(*read)->smb_cnt] == 'e' ? chck_e(read, ap, 1) :
		chck_e(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'g' || format[(*read)->smb_cnt] == 'G')
		format[(*read)->smb_cnt] == 'g' ? chck_g(read, ap, 1) :
		chck_g(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'p')
		chck_p(read, ap);
	else
		ft_k(read, format, ap, out);
	(*read)->prs < 0 ? (*read)->prs = 0 : 0;
}

void	ft_chck_size(t_rd **rd, const char *format)
{
	if (format[(*rd)->smb_cnt])
	{
		if (format[(*rd)->smb_cnt] == 'l' &&
		format[(*rd)->smb_cnt + 1] != 'l')
			(*rd)->size |= LONG_INT;
		else if (format[(*rd)->smb_cnt] == 'l' &&
		format[(*rd)->smb_cnt + 1] == 'l')
			(*rd)->size |= LONG_LONG_INT;
		else if (format[(*rd)->smb_cnt] == 'h' &&
		format[(*rd)->smb_cnt + 1] != 'h')
			(*rd)->size |= SHORT_INT;
		else if (format[(*rd)->smb_cnt] == 'h' &&
		format[(*rd)->smb_cnt + 1] == 'h')
			(*rd)->size |= SIGNED_CHAR;
		else if (format[(*rd)->smb_cnt] == 'j')
			(*rd)->size |= INT_MAXX;
		else if (format[(*rd)->smb_cnt] == 'z')
			(*rd)->size |= SIZE_T;
		else if (format[(*rd)->smb_cnt] == 't')
			(*rd)->size |= PTRDIFF_T;
		else if (format[(*rd)->smb_cnt] == 'L')
			(*rd)->size |= INT_64;
		ft_cycle(rd, format);
	}
}

void	ft_chck_precision(t_rd **read, const char *format, va_list **ap)
{
	int		r;

	(*read)->prs = 6;
	(*read)->kostil = 0;
	if (format[(*read)->smb_cnt + 1])
	{
		if (format[(*read)->smb_cnt] == '.')
		{
			r = 0;
			if (format[++(*read)->smb_cnt] == '*')
				r = va_arg(**ap, int);
			while (format[(*read)->smb_cnt] >= '0' &&
			format[(*read)->smb_cnt] <= '9')
			{
				r += format[(*read)->smb_cnt] - '0';
				if (format[(*read)->smb_cnt + 1] >= '0'
				&& format[(*read)->smb_cnt + 1] <= '9')
					r *= 10;
				(*read)->smb_cnt++;
			}
			if (r == 6)
				(*read)->kostil = 1;
			(*read)->prs = r;
		}
	}
}

void	ft_chck_wdth(t_rd **read, const char *format, va_list **ap)
{
	int	r;

	if (format[(*read)->smb_cnt + 1])
	{
		r = 0;
		if (format[(*read)->smb_cnt] == '*')
		{
			r = va_arg(**ap, int);
			(*read)->smb_cnt++;
			if (r < 0)
			{
				(*read)->flag |= F_MINUS;
				r *= -1;
			}
		}
		(*read)->width = r;
		if (format[(*read)->smb_cnt] >= '0'
		&& format[(*read)->smb_cnt] <= '9')
			r = 0;
		ft_cycle2(read, format, &r);
		(*read)->width = r;
	}
}

void	ft_chck_flags(t_rd **read, const char *format)
{
	(*read)->flag = 0;
	if ((*read)->smb_cnt < (*read)->strlen)
	{
		while ((format[(*read)->smb_cnt] == '-' ||
		format[(*read)->smb_cnt] == '+' ||
		format[(*read)->smb_cnt] == ' ' ||
		format[(*read)->smb_cnt] == '0' ||
		format[(*read)->smb_cnt] == '#'))
		{
			if (format[(*read)->smb_cnt] == '+')
				(*read)->flag |= F_PLUS;
			else if (format[(*read)->smb_cnt] == '-')
				(*read)->flag |= F_MINUS;
			else if (format[(*read)->smb_cnt] == ' ')
				(*read)->flag |= F_SPACE;
			else if (format[(*read)->smb_cnt] == '0')
				(*read)->flag |= F_ZERO;
			else if (format[(*read)->smb_cnt] == '#')
				(*read)->flag |= F_OCT;
			++(*read)->smb_cnt;
		}
	}
}
