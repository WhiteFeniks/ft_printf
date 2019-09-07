/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 08:08:51 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 08:08:53 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pw_to_str(int a, int b)
{
	char	*s;
	int		i;
	int		tmp;

	tmp = a;
	if (!(s = (char *)malloc(sizeof(char) * 17001)))
		return (NULL);
	ft_memset(s, '0', 17000);
	s[17000] = '\0';
	if (b == 0)
	{
		s[16999] = '1';
		return (s);
	}
	i = 17000;
	while (a)
	{
		s[--i] = (a % 10) + '0';
		a /= 10;
	}
	while (b-- > 1)
		str_ml(&s, tmp);
	return (s);
}
