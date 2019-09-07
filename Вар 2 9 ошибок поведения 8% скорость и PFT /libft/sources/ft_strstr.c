/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:02:59 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:10:59 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	if (!*needle && !*haystack)
		return (char *)haystack;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j]
			&& needle[j] && haystack[i + j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
