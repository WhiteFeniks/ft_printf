/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:18:35 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/16 19:57:28 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*m;
	t_list	*n;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	m = *alst;
	while (m)
	{
		del(m->content, m->content_size);
		n = m->next;
		free(m);
		m = n;
	}
	*alst = NULL;
}
