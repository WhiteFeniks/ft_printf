/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:32:46 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/22 15:32:49 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_pointer_str(t_saver *saver, va_list arg)
{
	char				*str;
	char				*final;
	unsigned long long	unsigned_nbr;

	unsigned_nbr = (unsigned long long)va_arg(arg, void *);
	str = ft_utoa_base(unsigned_nbr, 16);
	str = ft_lower(str);
	final = ft_strjoin("0x", str);
	free(str);
	if (unsigned_nbr == 0 && saver->precision == 0)
	{
		free(final);
		final = ft_strdup("0x");
	}
	final = add_precision(saver, final);
	final = add_min_width(saver, final);
	return (final);
}

void			print_pointer(t_saver *saver, va_list arg)
{
	char	*str;

	str = get_pointer_str(saver, arg);
	ft_put_string(str);
	free(str);
}
