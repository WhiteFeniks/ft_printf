/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:46:35 by mbodak            #+#    #+#             */
/*   Updated: 2016/12/18 16:21:29 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	size_t	i;

	ch = (char)c;
	i = ft_strlen(s);
	while (s[i] != ch)
	{
		if (i == 0)
			return (0);
		i--;
	}
	return ((char *)s + i);
}
