/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 00:20:17 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/04 00:44:25 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, size_t n)
{
	char	*c;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	c = dest + ft_strlen(dest);
	while (i < n && i < len)
	{
		c[i] = src[i];
		i = i + 1;
	}
	c[i] = '\0';
	return (dest);
}
