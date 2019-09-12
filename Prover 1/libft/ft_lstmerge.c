/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:27:18 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/10 16:31:19 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **dst, t_list *src)
{
	t_list	*tmp;

	if (*dst == NULL)
	{
		*dst = src;
		return ;
	}
	tmp = *dst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = src;
}
