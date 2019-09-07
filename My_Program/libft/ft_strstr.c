/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:36:19 by mbodak            #+#    #+#             */
/*   Updated: 2016/12/18 17:36:24 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;
	size_t j;

	if (!little[0])
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		j = 0;
		while ((big[i + j] == little[j]) && big[i + j])
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
