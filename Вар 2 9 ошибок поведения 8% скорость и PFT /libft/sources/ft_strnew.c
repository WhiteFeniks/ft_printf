/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:30:55 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:10:43 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (size == (size_t)-1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (0);
	ft_bzero(str, size + 1);
	return (str);
}
