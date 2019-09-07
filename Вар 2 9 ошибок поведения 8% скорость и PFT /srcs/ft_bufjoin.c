/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 01:29:19 by shunt             #+#    #+#             */
/*   Updated: 2019/08/07 01:29:21 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_bufjoin(char *s1, char *s2, int b1, int b2)
{
	char	*p;
	int		i;
	int		k;

	i = 0;
	k = -1;
	if (!s1 || !s2)
		return (0);
	if (!(p = (char *)malloc(sizeof(char) * (b1 + b2 + 1))))
		return (NULL);
	while (i < b1)
		p[i++] = *s1++;
	while (++k < b2)
		p[i++] = *s2++;
	p[i++] = '\0';
	return (p);
}
