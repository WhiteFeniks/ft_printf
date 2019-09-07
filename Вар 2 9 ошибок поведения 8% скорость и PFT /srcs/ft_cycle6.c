/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 03:33:42 by shunt             #+#    #+#             */
/*   Updated: 2019/08/07 03:33:43 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cycle6(t_wid *q, t_rd **read)
{
	while (++q->i != ((*read)->width - q->strlen + 1))
		q->res[++q->b] = '0';
	q->i = (*read)->mod[0] == '-' ? 0 : -1;
	if (q->b > 1 && (q->res[1] == 'x' || q->res[1] == 'X'))
		q->i = 1;
	while ((*read)->mod[++q->i])
		q->res[++q->b] = (*read)->mod[q->i];
	q->tmp = (*read)->mod;
	(*read)->mod = q->res;
	free((void *)q->tmp);
}
