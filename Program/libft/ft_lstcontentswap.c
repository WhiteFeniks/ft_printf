/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontentswap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 00:23:44 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/13 00:23:47 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcontentswap(t_list *a, t_list *b)
{
	size_t	c;
	void	*tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = a->content;
	c = a->content_size;
	a->content = b->content;
	a->content_size = b->content_size;
	b->content = tmp;
	b->content_size = c;
}
