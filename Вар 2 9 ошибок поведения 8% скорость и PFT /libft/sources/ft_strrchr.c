/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:15:16 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:10:49 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*beginning;

	beginning = (char *)s;
	while (*s != '\0')
		s++;
	if (c == 0)
		return ((char *)s);
	while (s > beginning && *s != c)
		s--;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
