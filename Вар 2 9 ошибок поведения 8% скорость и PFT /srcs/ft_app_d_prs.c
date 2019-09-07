/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_d_prs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 01:35:16 by shunt             #+#    #+#             */
/*   Updated: 2019/08/07 01:35:17 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_iei(t_rd **read, unsigned long strlen, int *b, unsigned long *i)
{
	char	*res;

	res = NULL;
	if ((*read)->mod_smb == 'p')
	{
		if (!(res = (char *)malloc(sizeof(char) * ((*read)->prs + 3))))
			return (NULL);
		res[(*read)->prs + 2] = '\0';
		res[0] = '0';
		res[1] = 'x';
		*b += 2;
		while ((*i)++ != ((*read)->prs - strlen - 2))
			res[++(*b)] = '0';
	}
	else if ((*read)->mod[0] == '-')
	{
		if (!(res = (char *)malloc(sizeof(char) * ((*read)->prs + 2))))
			return (NULL);
		res[(*read)->prs + 1] = '\0';
		res[0] = '-';
		++(*b);
		while ((*i)++ != ((*read)->prs - strlen - 1))
			res[++(*b)] = '0';
	}
	return (res);
}

static void	ft_ei(t_rd **read, unsigned long strlen, unsigned long i, int b)
{
	char	*res;
	char	*tmp;

	if ((*read)->mod_smb == 'p' || (*read)->mod[0] == '-')
		res = ft_iei(read, strlen, &b, &i);
	else
	{
		if (!(res = (char *)malloc(sizeof(char) * ((*read)->prs + 1))))
			return ;
		res[(*read)->prs] = '\0';
		while (i++ != ((*read)->prs - strlen))
			res[++b] = '0';
	}
	i = 0;
	(*read)->mod[0] == '-' ? (*read)->mod[0] = '0' : 0;
	(*read)->mod_smb == 'p' ? (*read)->mod[1] = '0' : 0;
	while ((*read)->mod[i])
		res[++b] = (*read)->mod[i++];
	tmp = (*read)->mod;
	(*read)->mod = res;
	free((void *)tmp);
}

static void	ft_fei(t_rd **read, unsigned long i, int b)
{
	unsigned long	strlen;
	char			*res;
	char			*tmp;

	strlen = (*read)->mod[0] == '-' ? ft_strlen((*read)->mod) - 1 :
			ft_strlen((*read)->mod);
	if ((*read)->mod_smb == 'p')
		strlen -= 2;
	if (!(*read)->prs && (*read)->mod[0] == '0' && !(*read)->mod[1] &&
		(*read)->kostil == 1 && (*read)->mod_smb != 'p')
	{
		if (!(res = (char *)malloc(sizeof(char) * 1)))
			return ;
		res[0] = '\0';
		tmp = (*read)->mod;
		(*read)->mod = res;
		free((void *)tmp);
	}
	else if ((*read)->prs > (long)strlen)
		ft_ei(read, strlen, i, b);
}

int			ft_app_d_prs(t_rd **read)
{
	unsigned long		i;
	int					b;

	i = 0;
	b = -1;
	if ((*read)->mod[0] == '0' && !(*read)->mod[1] && (*read)->kostil == 3)
		(*read)->mod[0] = '\0';
	else if ((*read)->mod_smb == 'p' && (*read)->mod[2] == '0' &&
		!(*read)->mod[3] && (*read)->kostil == 3)
		(*read)->mod[2] = '\0';
	else if ((*read)->mod)
		ft_fei(read, i, b);
	return (1);
}
