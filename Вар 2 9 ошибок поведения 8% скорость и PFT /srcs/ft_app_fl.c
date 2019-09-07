/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_fl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 01:37:15 by shunt             #+#    #+#             */
/*   Updated: 2019/08/07 01:37:16 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_i(t_rd **read, unsigned long strlen, char **res)
{
	unsigned long	i;
	unsigned long	b;

	i = 0;
	b = 0;
	if ((*read)->sign && !((*read)->flag & F_MINUS))
	{
		if ((*read)->mod[0] == ' ' || (*read)->mod[0] == '0')
			(*res)[0] = ' ';
		else
			(*res)[0] = (*read)->mod[0];
		while ((*read)->mod[++i])
			(*res)[i] = (*read)->mod[i];
	}
	else
	{
		(*res)[0] = ' ';
		while (++b < strlen + 1)
		{
			(*res)[b] = (*read)->mod[i];
			++i;
		}
	}
}

int			ft_app_fl(t_rd **read)
{
	unsigned long		strlen;
	char				*res;
	char				*tmp;

	if ((*read)->mod)
	{
		if ((*read)->flag & F_SPACE && !((*read)->flag & F_PLUS) &&
			(*read)->mod[0] != '-' && (*read)->mod_smb != 'u' &&
			(*read)->mod_smb != '%' && (*read)->mod_smb != 'c')
		{
			strlen = (*read)->sign ? ft_strlen((*read)->mod) - 1 :
					ft_strlen((*read)->mod);
			if (!(res = (char *)malloc(sizeof(char) * (strlen + 2))))
				return (0);
			res[strlen + 1] = '\0';
			ft_i(read, strlen, &res);
			tmp = (*read)->mod;
			(*read)->mod = res;
			free((void *)tmp);
		}
	}
	return (SUCCESS);
}
