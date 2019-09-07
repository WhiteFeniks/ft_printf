/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 00:46:52 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/04 03:13:14 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_compare_str(const char *a, const char *b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (0);
		i = i + 1;
	}
	return (1);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	char	*c;
	int		len;

	if (*needle == '\0')
		return ((char*)haystack);
	len = ft_strlen(needle);
	c = (char*)haystack;
	while (*c != '\0')
	{
		if (ft_compare_str(c, needle, len))
			return (c);
		c = c + 1;
	}
	return (0);
}
