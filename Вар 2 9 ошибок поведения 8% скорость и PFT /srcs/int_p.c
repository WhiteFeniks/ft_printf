/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:43:13 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 12:43:14 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_p(int e, char *man)
{
	char	*in;
	char	*tmp;
	int		i;

	tmp = NULL;
	if (!(in = (char *)malloc(sizeof(char) * 17001)))
		return (NULL);
	ft_memset(in, '0', 17000);
	in[17000] = '\0';
	i = -1;
	while (--e > -1 && man[++i])
		if (man[i] == '1')
		{
			tmp ? free(tmp) : 0;
			if (!(tmp = pw_to_str(2, e)))
				return (NULL);
			str_ad(&in, tmp);
		}
	return (in);
}
