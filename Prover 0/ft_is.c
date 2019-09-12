/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:13:17 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/03 19:13:20 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_flag(const char *string, size_t i)
{
	if (string[i] == '+')
		return (1);
	if (string[i] == '-')
		return (1);
	if (string[i] == ' ')
		return (1);
	if (string[i] == '0')
		return (1);
	if (string[i] == '#')
		return (1);
	return (0);
}

int			is_size(const char *string, size_t i)
{
	if (string[i] == 'h' && string[i + 1] == 'h')
		return (2);
	if (string[i] == 'h')
		return (1);
	if (string[i] == 'l')
		return (1);
	if (string[i] == 'l' && string[i + 1] == 'l')
		return (2);
	if (string[i] == 'j')
		return (1);
	if (string[i] == 'z')
		return (1);
	return (0);
}

t_size		get_size(const char *string, size_t i)
{
	if (string[i] == 'h' && string[i + 1] == 'h')
		return (HH);
	if (string[i] == 'h')
		return (H);
	if (string[i] == 'l')
		return (L);
	if (string[i] == 'l' && string[i + 1] == 'l')
		return (LL);
	if (string[i] == 'j')
		return (J);
	if (string[i] == 'z')
		return (Z);
	return (DEF);
}
