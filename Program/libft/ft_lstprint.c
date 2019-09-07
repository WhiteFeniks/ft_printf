/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:00:36 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/10 16:42:49 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	t_list		*e;
	size_t		i;

	e = lst;
	while (e)
	{
		i = 0;
		while (i < (e->content_size))
		{
			ft_putchar(((char*)(e->content))[i]);
			i = i + 1;
		}
		ft_putchar('\n');
		e = e->next;
	}
}
