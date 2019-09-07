/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <wtorwold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:28:46 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/16 20:16:11 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			print_c(t_pattern tmp, char c)
{
	int			s;

	s = tmp.width - 1;
	if (tmp.minus == 1)
	{
		ft_putchar(c);
		while (s-- > 0)
			ft_putchar(' ');
	}
	else
	{
		if (tmp.zero == 1)
		{
			while (s-- > 0)
				ft_putnbr(0);
			ft_putchar(c);
		}
		else
		{
			while (s-- > 0)
				ft_putchar(' ');
			ft_putchar(c);
		}
	}
}
