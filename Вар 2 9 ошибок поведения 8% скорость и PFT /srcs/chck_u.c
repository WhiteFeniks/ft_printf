/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 23:56:14 by shunt             #+#    #+#             */
/*   Updated: 2019/07/20 23:56:16 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chck_u(t_rd **read, va_list **ap)
{
	(*read)->mod_smb = 'u';
	if ((*read)->size == 0)
		(*read)->mod = ft_u(va_arg(**ap, unsigned int));
	else if ((*read)->size == 1)
		(*read)->mod = ft_u(va_arg(**ap, unsigned long));
	else if ((*read)->size == 2)
		(*read)->mod = ft_u(va_arg(**ap, unsigned long long));
	else if ((*read)->size == 4)
		(*read)->mod = ft_u((unsigned short)va_arg(**ap, unsigned int));
	else if ((*read)->size == 8)
		(*read)->mod = ft_u((unsigned char)va_arg(**ap, unsigned int));
	else if ((*read)->size == 16)
		(*read)->mod = ft_u(va_arg(**ap, uintmax_t));
	else if ((*read)->size == 32 || (*read)->size == 64)
		(*read)->mod = ft_u(va_arg(**ap, ssize_t));
	else if ((*read)->size == 128)
		(*read)->mod = ft_u(va_arg(**ap, u_int64_t));
}
