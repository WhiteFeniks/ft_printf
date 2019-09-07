/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 00:20:47 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/04 03:11:32 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	char	*c;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s2);
	c = s1 + ft_strlen(s1);
	while (i <= len)
	{
		c[i] = s2[i];
		i = i + 1;
	}
	return (s1);
}
