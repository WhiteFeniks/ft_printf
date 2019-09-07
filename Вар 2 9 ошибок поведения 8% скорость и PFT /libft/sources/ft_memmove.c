/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:07:56 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:09:04 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*a;
	char	*b;

	i = 0;
	a = (char *)dst;
	b = (char *)src;
	if (b < a)
		while (++i <= len)
			a[len - i] = b[len - i];
	else
		while (len-- > 0)
		{
			a[i] = b[i];
			i++;
		}
	return (dst);
}
