/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 01:36:07 by shunt             #+#    #+#             */
/*   Updated: 2019/08/07 03:41:36 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_cycle4(t_wid *q, t_rd **read)
{
	while (++q->i != ((*read)->width - q->strlen + 1))
		q->res[++q->b] = ' ';
	q->i = -1;
	while ((*read)->mod[++q->i])
		q->res[++q->b] = (*read)->mod[q->i];
	q->tmp = (*read)->mod;
	(*read)->mod = q->res;
	free((void *)q->tmp);
}

static void	ft_cycle3(t_wid **q, t_rd **read)
{
	if (((*read)->mod_smb == 'x' ||
		(*read)->mod_smb == 'X') && (*q)->strlen > 2 &&
		(*read)->mod[0] == '0' && ((*read)->mod[1] == 'x' ||
		(*read)->mod[1] == 'X'))
	{
		(*q)->res[0] = (*read)->mod[0];
		(*q)->res[1] = (*read)->mod[1];
		(*q)->b += 2;
		(*q)->strlen -= 2;
		(*q)->i += 2;
	}
}

static void	ft_wid2(t_wid *q, t_rd **read)
{
	if ((*read)->flag & F_ZERO && !((*read)->flag & F_MINUS) &&
		((!(*read)->prs || ((*read)->prs == 6 &&
							!(*read)->kostil) || (*read)->mod_smb == 'f' ||
		(*read)->mod_smb == 'F' || (*read)->mod_smb == 'e' ||
		(*read)->mod_smb == 'E' || (*read)->mod_smb == 'g' ||
		(*read)->mod_smb == 'G' || (*read)->mod_smb == 'c' ||
		(*read)->mod_smb == 's')))
	{
		if ((*read)->mod[0] == '-')
		{
			q->res[0] = '-';
			++q->b;
		}
		else
			ft_cycle3(&q, read);
		ft_cycle6(q, read);
	}
	else
		ft_cycle4(q, read);
}

static void	ft_cycle5(t_wid *q, t_rd **rd)
{
	while (q->i < q->strlen)
	{
		q->res[++q->b] = (*rd)->mod[q->i];
		++q->i;
	}
	while (++q->b < (*rd)->width)
		q->res[q->b] = ' ';
	(*rd)->zero ? (*rd)->zero = (*rd)->width : 0;
	q->tmp = (*rd)->mod;
	(*rd)->mod = q->res;
	free((void *)q->tmp);
}

int			ft_app_width(t_rd **rd)
{
	t_wid	q;

	q.i = 0;
	q.b = -1;
	if ((*rd)->mod)
	{
		if ((*rd)->width)
		{
			q.strlen = ft_strlen((*rd)->mod) + (*rd)->zero;
			if ((*rd)->width > (long)q.strlen)
			{
				(*rd)->sign = 1;
				if (!(q.res = (char *)malloc(sizeof(char) *
								((*rd)->width) + 1)))
					return (0);
				q.res[(*rd)->width] = '\0';
				if ((*rd)->flag & F_MINUS)
					ft_cycle5(&q, rd);
				else
					ft_wid2(&q, rd);
			}
		}
	}
	return (SUCCESS);
}
