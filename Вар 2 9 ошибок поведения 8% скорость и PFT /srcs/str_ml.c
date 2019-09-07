/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ml.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 08:07:39 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 08:07:41 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_ml(char **s1, int m)
{
	char	*tmp;
	int		i;
	int		l;

	l = ft_strlen(*s1);
	if (!(tmp = (char *)malloc(sizeof(char) * (l + 1))))
		return ;
	i = -1;
	while ((*s1)[++i])
		tmp[i] = (*s1)[i];
	tmp[i] = '\0';
	if (m == 0)
		ft_memset((*s1), '0', l);
	while (--m > 0)
		str_ad(s1, tmp);
}
