/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 09:29:53 by shunt             #+#    #+#             */
/*   Updated: 2019/06/23 09:29:55 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_str(char **s, char **t, char **c)
{
	int		i;
	int		k;

	if (*s)
		free(*s);
	i = (*c) ? ft_strlen(*t) + ft_strlen(*c) : ft_strlen(*t);
	if (!(*s = (char *)malloc(sizeof(char) * (i + 1))))
		return ;
	(*s)[i] = '\0';
	i = -1;
	while ((*t)[++i])
		(*s)[i] = (*t)[i];
	k = -1;
	if (*c)
		while ((*c)[++k])
			(*s)[i++] = (*c)[k];
	(*c) ? free(*c) : 0;
	free(*t);
}
