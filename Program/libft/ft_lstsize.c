/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:38:27 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/10 15:15:32 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *liste)
{
	size_t	len;
	t_list	*l;

	len = 0;
	l = liste;
	while (l)
	{
		len = len + 1;
		l = l->next;
	}
	return (len);
}
