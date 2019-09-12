/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:46:05 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/16 20:50:17 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*e;
	t_list	*l;
	t_list	*n;

	if (lst == NULL || f == NULL)
		return (NULL);
	e = lst;
	n = f(e);
	l = n;
	e = e->next;
	while (e)
	{
		while (n->next)
			n = n->next;
		n->next = f(e);
		e = e->next;
	}
	return (l);
}
