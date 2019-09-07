/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_o_fr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:11:15 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 14:11:17 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*res_o_fr(char *in, int sign)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	while (in[++i] == '0')
		;
	res = (sign) ? (char *)malloc(sizeof(char) * (17003 - i)) :
			(char *)malloc(sizeof(char) * (17002 - i));
	res[17001 - i] = '\0';
	j = -1;
	sign ? res[++j] = '-' : 0;
	while (in[i])
		res[++j] = in[i++];
	res[++j] = '.';
	return (res);
}
