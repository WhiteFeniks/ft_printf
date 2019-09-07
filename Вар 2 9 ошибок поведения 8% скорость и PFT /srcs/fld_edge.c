/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fld_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 09:10:52 by shunt             #+#    #+#             */
/*   Updated: 2019/06/24 09:11:07 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*edgrt(int c)
{
	char	*r;

	if (!(r = (char *)malloc(sizeof(char) * 4)))
		return (NULL);
	if (c == 3 || c == 4)
	{
		r[0] = c == 3 ? 'i' : 'I';
		r[1] = c == 3 ? 'n' : 'N';
		r[2] = c == 3 ? 'f' : 'F';
		r[3] = '\0';
	}
	else
	{
		r[0] = c == 5 ? 'n' : 'N';
		r[1] = c == 5 ? 'a' : 'A';
		r[2] = c == 5 ? 'n' : 'N';
		r[3] = '\0';
	}
	return (r);
}

static char	*edgr(int c)
{
	char	*r;

	if (!(r = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	r[0] = '-';
	r[1] = c == 1 ? 'i' : 'I';
	r[2] = c == 1 ? 'n' : 'N';
	r[3] = c == 1 ? 'f' : 'F';
	r[4] = '\0';
	return (r);
}

char		*fld_edge(char **man, int sign, int c)
{
	if (ft_strcmp(*man,
			"1000000000000000000000000000000000000000000000000000000000000000")
			== 0)
	{
		free(*man);
		if (sign)
			return (c ? edgr(1) : edgr(2));
		else
			return (c ? edgrt(3) : edgrt(4));
	}
	if (ft_strcmp(*man,
			"1100000000000000000000000000000000000000000000000000000000000000")
			== 0)
	{
		free(*man);
		return (c ? edgrt(5) : edgrt(6));
	}
	return (NULL);
}
