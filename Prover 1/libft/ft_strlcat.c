/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:23:25 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/10 10:26:25 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		len_d;

	d = dest;
	s = src;
	n = size;
	while (n-- != 0 && *d != '\0')
		d = d + 1;
	len_d = d - dest;
	n = size - len_d;
	if (n == 0)
		return (len_d + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n = n - 1;
		}
		s = s + 1;
	}
	*d = '\0';
	return (len_d + (s - src));
}
