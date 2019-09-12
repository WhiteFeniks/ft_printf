/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 01:05:18 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/16 21:05:18 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_compare_str(const char *a, const char *b, int n, char *end)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if ((a + i) == end && i < n - 1)
			return (0);
		if (a[i] != b[i])
			return (0);
		i = i + 1;
	}
	return (1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*c;
	int		n;

	if (*needle == '\0')
		return ((char*)haystack);
	n = ft_strlen(needle);
	c = (char*)haystack;
	while (*c != '\0' && (size_t)(c - haystack) < len)
	{
		if (ft_compare_str(c, needle, n, (char*)haystack + len))
			return (c);
		c = c + 1;
	}
	return (0);
}
