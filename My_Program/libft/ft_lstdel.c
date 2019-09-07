/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:12:43 by mbodak            #+#    #+#             */
/*   Updated: 2016/12/17 13:08:14 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *t_next;

	if (!alst || !*alst || !del)
		return ;
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		t_next = (*alst)->next;
		free(*alst);
		*alst = NULL;
		*alst = t_next;
	}
	*alst = NULL;
}
