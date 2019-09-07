/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_w_fr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:11:15 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 14:11:17 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*res_ne(char *fr, int i, int sign)
{
	char	*res;
	int		j;

	res = (sign) ? (char *)malloc(sizeof(char) * (17002)) :
			(char *)malloc(sizeof(char) * (17001));
	if (sign)
		res[17001] = '\0';
	else
		res[17000] = '\0';
	j = -1;
	sign ? res[++j] = '-' : 0;
	res[++j] = '0';
	res[++j] = '.';
	while (fr[++i])
		res[++j] = fr[i];
	return (res);
}

char	*res_w_fr(int e, char *in, char *fr, int sign)
{
	char	*res;
	int		i;
	int		j;

	if (e < 0)
		return (res_ne(fr, 16935 + e, sign));
	i = -1;
	while (in[++i] == '0')
		;
	res = (sign) ? (char *)malloc(sizeof(char) * (17066 - i - e)) :
			(char *)malloc(sizeof(char) * (17065 - i - e));
	if (sign)
		res[17065 - i - e] = '\0';
	else
		res[17064 - i - e] = '\0';
	j = -1;
	sign ? res[++j] = '-' : 0;
	while (in[i])
		res[++j] = in[i++];
	res[++j] = '.';
	i = 16936 + e;
	while (fr[++i])
		res[++j] = fr[i];
	return (res);
}
