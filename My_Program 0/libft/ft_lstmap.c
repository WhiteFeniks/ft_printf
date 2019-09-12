/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:21:01 by mbodak            #+#    #+#             */
/*   Updated: 2016/12/17 13:25:56 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *f_tmp;
	t_list *result;

	if (!f)
		return (NULL);
	result = NULL;
	tmp = NULL;
	while (lst)
	{
		f_tmp = f(lst);
		if (!result)
			result = f_tmp;
		if (!tmp)
			tmp = f_tmp;
		else
			tmp->next = f_tmp;
		tmp = f_tmp;
		lst = lst->next;
	}
	return (result);
}
