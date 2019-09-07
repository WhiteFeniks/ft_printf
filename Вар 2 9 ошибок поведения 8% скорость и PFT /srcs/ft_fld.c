/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 01:46:25 by shunt             #+#    #+#             */
/*   Updated: 2019/06/07 01:46:27 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fld(long double f, int c)
{
	t_flts	l;
	int		s[2];
	char	*res;
	char	*in;
	char	*fr;

	l.u = f;
	if (!(res = mantis(l)))
		return (NULL);
	s[0] = (l.y[4] & 0x8000) ? 1 : 0;
	s[1] = mexp(l);
	if (s[1] == 16384)
		return (fld_edge(&res, s[0], c));
	if (!(in = int_p(s[1] + 1, res)))
		return (NULL);
	if (!(fr = fr_p(s[1], res)))
		return (NULL);
	free(res);
	res = (s[1] < 63) ? res_w_fr(s[1], in, fr, s[0]) : res_o_fr(in, s[0]);
	free(in);
	free(fr);
	return (res ? res : NULL);
}
