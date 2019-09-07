/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:25:32 by huller            #+#    #+#             */
/*   Updated: 2019/06/24 17:25:34 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_i(t_rd **read, int i, int b)
{
	unsigned long	strlen;
	char			*res;
	char			*tmp;

	if ((*read)->width && ((*read)->mod[0] == ' ' || (*read)->mod[0] == '0'))
	{
		while ((*read)->mod[i] == ' ')
			++i;
		i > 0 ? (*read)->mod[i - 1] = '0' : 0;
	}
	else
	{
		strlen = ft_strlen((*read)->mod);
		if (!(res = (char *)malloc(sizeof(char) * (strlen + 2))))
			return ;
		res[strlen + 1] = '\0';
		res[0] = '0';
		while ((*read)->mod[i])
			res[++b] = (*read)->mod[i++];
		tmp = (*read)->mod;
		(*read)->mod = res;
		free((void *)tmp);
	}
}

static void	ft_ei(t_rd **read, int i)
{
	int				b;
	unsigned long	strlen;
	char			*tmp;
	char			*res;

	b = 1;
	strlen = ft_strlen((*read)->mod);
	if (!(res = (char *)malloc(sizeof(char) * (strlen + 3))))
		return ;
	res[strlen + 2] = '\0';
	res[0] = '0';
	res[1] = (*read)->mod_smb == 'x' ? 'x' : 'X';
	while ((*read)->mod[i])
	{
		res[++b] = (*read)->mod[i];
		++i;
	}
	tmp = (*read)->mod;
	(*read)->mod = res;
	free((void *)tmp);
}

int			ft_add_sharp(t_rd **read)
{
	int				b;
	unsigned long	i;

	i = 0;
	b = 0;
	if ((*read)->kostil == 4 && ((*read)->mod_smb == 'o' ||
		(*read)->mod_smb == 'x' || (*read)->mod_smb == 'X'))
		return (SUCCESS);
	if ((*read)->flag & F_OCT)
	{
		if ((*read)->mod_smb == 'o' && !((*read)->mod[0] == '0' &&
			!(*read)->mod[1]))
			ft_i(read, i, b);
		else if (((*read)->mod_smb == 'x' || (*read)->mod_smb == 'X') &&
			!((*read)->mod[0] == '0' && !(*read)->mod[1]) && (*read)->mod[0])
			ft_ei(read, i);
	}
	return (SUCCESS);
}
