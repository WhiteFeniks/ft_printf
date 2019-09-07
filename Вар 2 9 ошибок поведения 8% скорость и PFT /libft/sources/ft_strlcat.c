/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:09:39 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:10:18 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t res;

	i = 0;
	j = 0;
	res = 0;
	while (dst[i] != '\0')
		i++;
	if (i < size)
	{
		while (src[j] != '\0' && i < (size - 1))
			dst[i++] = src[j++];
		dst[i] = '\0';
		while (src[j] != '\0')
		{
			j++;
			i++;
		}
		return (i);
	}
	dst[i] = '\0';
	while (src[res] != '\0')
		res++;
	return (res + size);
}
