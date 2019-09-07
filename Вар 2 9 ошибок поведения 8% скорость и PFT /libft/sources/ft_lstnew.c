/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:44:05 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:08:35 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newone;

	if (!(newone = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (content == NULL || content_size == 0)
	{
		newone->content = NULL;
		newone->content_size = 0;
	}
	else
	{
		if (!(newone->content = malloc(content_size)))
		{
			free((void *)newone);
			return (0);
		}
		newone->content_size = content_size;
		newone->content = ft_memcpy(newone->content, content, content_size);
	}
	newone->next = NULL;
	return (newone);
}
