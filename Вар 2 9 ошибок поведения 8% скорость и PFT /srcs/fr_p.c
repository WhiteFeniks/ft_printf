/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:44:18 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 12:44:20 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fr_ne(int e, char *man)
{
	char	*fr;
	int		i;
	int		k;

	k = e + 64;
	fr = (char *)malloc(sizeof(char) * 17001);
	ft_memset(fr, '0', 17000);
	fr[17000] = '\0';
	i = -1;
	while (man[++i])
	{
		if (man[i] == '1')
			str_ad(&fr, add_z(pw_to_str(5, e), k - e));
		++e;
	}
	return (fr);
}

char		*fr_p(int i, char *man)
{
	char	*fr;
	int		len;
	int		e;

	if (i < 0)
		return (fr_ne(i * -1, man));
	fr = (char *)malloc(sizeof(char) * 17001);
	ft_memset(fr, '0', 17000);
	fr[17000] = '\0';
	len = ft_strlen(man + i + 1);
	e = 1;
	while (man[++i])
	{
		if (man[i] == '1')
			str_ad(&fr, add_z(pw_to_str(5, e), len - e));
		++e;
	}
	return (fr);
}
