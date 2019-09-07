/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:14:28 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:10:52 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	buff;

	i = 0;
	len = ft_strlen(str);
	while (len - 1 > i)
	{
		buff = str[i];
		str[i] = str[len - 1];
		str[len - 1] = buff;
		len--;
		i++;
	}
	return (str);
}
