/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:07:08 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:08:51 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*b;

	p = ((unsigned char *)s1);
	b = ((unsigned char *)s2);
	while (n > 0)
	{
		if (*(p++) != *(b++))
			return ((int)(*(p - 1) - *(b - 1)));
		n--;
	}
	return (0);
}
