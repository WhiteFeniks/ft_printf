/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 23:39:14 by huller            #+#    #+#             */
/*   Updated: 2019/08/06 23:40:04 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chck_di(t_rd **read, va_list **ap, int a)
{
	(*read)->mod_smb = a ? 'd' : 'i';
	if ((*read)->size == 0)
		(*read)->mod = s_itoa(va_arg(**ap, int));
	else if ((*read)->size == 1)
		(*read)->mod = s_itoa(va_arg(**ap, long));
	else if ((*read)->size == 2)
		(*read)->mod = s_itoa(va_arg(**ap, long long));
	else if ((*read)->size == 4)
		(*read)->mod = s_itoa((short)va_arg(**ap, int));
	else if ((*read)->size == 8)
		(*read)->mod = s_itoa((char)va_arg(**ap, int));
	else if ((*read)->size == 16)
		(*read)->mod = s_itoa(va_arg(**ap, uintmax_t));
	else if ((*read)->size == 32 || (*read)->size == 64)
		(*read)->mod = s_itoa(va_arg(**ap, ssize_t));
	else if ((*read)->size == 128)
		(*read)->mod = s_itoa(va_arg(**ap, u_int64_t));
}
