/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 05:58:07 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/16 20:13:36 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((str = malloc(len1 + len2 + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i = i + 1;
	}
	i = 0;
	while (i < len2)
	{
		str[len1 + i] = s2[i];
		i = i + 1;
	}
	str[len1 + i] = '\0';
	return (str);
}
