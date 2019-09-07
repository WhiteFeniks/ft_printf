/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 01:37:28 by shunt             #+#    #+#             */
/*   Updated: 2019/06/04 01:37:43 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cycle2(t_rd **read, const char *format, int *r)
{
	while (format[(*read)->smb_cnt] >= '0'
		&& format[(*read)->smb_cnt] <= '9')
	{
		*r += format[(*read)->smb_cnt] - '0';
		if (format[(*read)->smb_cnt + 1] >= '0'
			&& format[(*read)->smb_cnt + 1] <= '9')
			*r *= 10;
		(*read)->smb_cnt++;
	}
}

void	ft_cycle(t_rd **rd, const char *format)
{
	while (format[(*rd)->smb_cnt] == 'l' || format[(*rd)->smb_cnt] == 'h' ||
		format[(*rd)->smb_cnt] == 'j' || format[(*rd)->smb_cnt] == 'z' ||
		format[(*rd)->smb_cnt] == 'L' || format[(*rd)->smb_cnt] == 't')
		++((*rd)->smb_cnt);
}

int		ft_k(t_rd **read, const char *format, va_list **ap, t_out *out)
{
	if (format[(*read)->smb_cnt] == 'o')
		chck_o(read, ap);
	else if (format[(*read)->smb_cnt] == 'b')
		chck_b(read, ap);
	else if (format[(*read)->smb_cnt] == 'x')
		chck_x(read, ap);
	else if (format[(*read)->smb_cnt] == 'X')
		chck_xu(read, ap);
	else if (format[(*read)->smb_cnt] == 'c' || format[(*read)->smb_cnt] == 'C')
		chck_c(read, ap);
	else if (format[(*read)->smb_cnt] == 'u' || format[(*read)->smb_cnt] == 'U')
	{
		if (format[(*read)->smb_cnt] == 'U')
			(*read)->size = 2;
		chck_u(read, ap);
	}
	else if (format[(*read)->smb_cnt] == '%')
		ft_put_percent(read);
	else if (!(chck_nthng(format, out, read)))
		return (0);
	return (SUCCESS);
}

void	ft_free_lists(t_rd **read)
{
	t_rd *tmp;

	while ((*read))
	{
		tmp = (*read);
		(*read)->mod ? free((*read)->mod) : 0;
		(*read)->mod2 ? free((*read)->mod2) : 0;
		*read = (*read)->prev;
		free(tmp);
	}
}
