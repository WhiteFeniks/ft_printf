/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 06:06:41 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/16 20:26:19 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	beg;
	size_t	end;
	size_t	i;

	if (s == NULL)
		return (NULL);
	beg = 0;
	end = ft_strlen(s) - 1;
	while ((s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t') && s[beg])
		beg = beg + 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && s[end])
		end = end - 1;
	if (beg >= ft_strlen(s) || end <= 0)
		return (ft_strdup(""));
	if ((str = malloc(end - beg + 2)) == NULL)
		return (NULL);
	i = 0;
	while (beg + i <= end)
	{
		str[i] = s[beg + i];
		i = i + 1;
	}
	str[i] = '\0';
	return (str);
}
