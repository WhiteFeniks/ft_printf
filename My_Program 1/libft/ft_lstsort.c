/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:43:20 by yez-zain          #+#    #+#             */
/*   Updated: 2018/11/07 10:31:23 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list *liste)
{
	t_list	*l;
	int		sorted;
	size_t	max_size;

	if (liste == NULL || liste->next == NULL)
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		l = liste;
		while (l->next)
		{
			max_size = l->next->content_size;
			if (max_size < l->content_size)
				max_size = l->content_size;
			if (ft_memcmp(l->content, l->next->content, max_size) > 0)
			{
				ft_lstcontentswap(l, l->next);
				sorted = 0;
			}
			l = l->next;
		}
	}
}
