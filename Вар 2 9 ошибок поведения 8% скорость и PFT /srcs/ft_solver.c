/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 01:33:20 by shunt             #+#    #+#             */
/*   Updated: 2019/08/07 01:33:21 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_solver(t_rd **read, t_out *output)
{
	if ((((*read)->mod_smb == 'd' || (*read)->mod_smb == 'i' ||
		(*read)->mod_smb == 'u' || (*read)->mod_smb == 'p') &&
		((*read)->prs)) || (!(*read)->prs && (*read)->mod[0] == '0' &&
		(!(*read)->mod[1] || ((*read)->mod[2] == '0' && !(*read)->mod[3]))))
	{
		if (!(ft_app_d_prs(read)))
			return (0);
	}
	if ((*read)->mod_smb == 's' && ((*read)->prs || (*read)->kostil == 3))
		if ((*read)->prs < (long)ft_strlen((*read)->mod))
			(*read)->mod[(*read)->prs] = '\0';
	if (!(ft_add_sharp(read)))
		return (0);
	if (!(ft_app_width(read)))
		return (0);
	if (!(ft_app_fl(read)))
		return (0);
	if (!(ft_add_pl(read)))
		return (0);
	if (!(ft_put_out(read, &output)))
		return (0);
	return (SUCCESS);
}
