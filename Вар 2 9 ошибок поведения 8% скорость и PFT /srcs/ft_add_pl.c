/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 01:38:14 by shunt             #+#    #+#             */
/*   Updated: 2019/08/07 01:38:15 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_i(t_rd **read, int b, unsigned long strlen, int i)
{
	char	*tmp;
	char	*res;

	if (!((*read)->flag & F_MINUS))
	{
		while ((*read)->mod[b] == ' ')
			b++;
		(b) ? (*read)->mod[--b] = '+' : 0;
		(!b && (*read)->flag & F_ZERO) ? ((*read)->mod[b] = '+') : 0;
	}
	else
	{
		strlen = ft_strlen((*read)->mod);
		if (!(res = (char *)malloc(sizeof(char) * (strlen + 1))))
			return ;
		res[strlen] = '\0';
		(res[0] = '+');
		b = 0;
		while ((*read)->mod[i] && --strlen > 0)
			res[++b] = (*read)->mod[i++];
		tmp = (*read)->mod;
		(*read)->mod = res;
		free((void *)tmp);
	}
}

static void	ft_ei(t_rd **read, int i, int b)
{
	unsigned long	strlen;
	char			*res;
	char			*tmp;

	strlen = ft_strlen((*read)->mod);
	if (!(res = (char *)malloc(sizeof(char) * (strlen + 2))))
		return ;
	res[strlen + 1] = '\0';
	if ((*read)->width)
		(res[b] = '+');
	else
		(res[0] = '+');
	b = 0;
	while ((*read)->mod[i])
	{
		res[++b] = (*read)->mod[i];
		++i;
	}
	tmp = (*read)->mod;
	(*read)->mod = res;
	free((void *)tmp);
}

int			ft_add_pl(t_rd **read)
{
	unsigned long		i;
	int					b;
	unsigned long		strlen;
	char				*res;
	char				*tmp;

	i = 0;
	b = 0;
	if ((*read)->mod)
	{
		if ((*read)->flag & F_PLUS && (!(ft_strchr((*read)->mod, 45))) &&
			(*read)->mod_smb != 'u' && (*read)->mod_smb != 's')
		{
			if ((*read)->width && (*read)->sign)
				ft_i(read, b, strlen, i);
			else
				ft_ei(read, i, b);
		}
	}
	return (SUCCESS);
}
