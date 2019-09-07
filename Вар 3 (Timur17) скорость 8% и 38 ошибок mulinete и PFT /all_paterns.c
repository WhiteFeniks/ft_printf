/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <wtorwold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:53:09 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/14 23:05:38 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

void				new_pattern(t_pattern *tmp)
{
	tmp->hash = 0;
	tmp->m = 0;
	tmp->minus = 0;
	tmp->plus = 0;
	tmp->space = 0;
	tmp->zero = 0;
	tmp->width = 0;
	tmp->precision = -1;
	tmp->point = 0;
	tmp->h = 0;
	tmp->hh = 0;
	tmp->l = 0;
	tmp->hh = 0;
	tmp->j = 0;
	tmp->z = 0;
	tmp->ll = 0;
	tmp->help = 0;
	tmp->type = 0;
}

int					ft_cast(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L')
		return (1);
	else
		return (0);
}

int					type(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' ||
		c == 'D' || c == 'i' || c == 'o' || c == 'O' ||
		c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C' || c == 'f')
		return (1);
	else
		return (0);
}

int					ft_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}
