/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ox.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 23:55:44 by shunt             #+#    #+#             */
/*   Updated: 2019/08/07 01:47:52 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ro(char **s, size_t prs, t_rd **read, int g)
{
	char	*r;
	int		i[3];

	i[2] = ft_strlen(*s);
	(*read)->kostil = g ? 5 : 4;
	(*s[0] == '0' && !(*s)[1]) ? (*read)->kostil = 4 : 0;
	if ((*s)[0] == '0' && !(*s)[1] && !prs && (!((*read)->flag & F_OCT) ||
			(*read)->mod_smb == 'x' || (*read)->mod_smb == 'X'))
	{
		if (!(r = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		r[0] = '\0';
		return (r);
	}
	if (!(r = (char *)malloc(sizeof(char) * (prs + 1))))
		return (NULL);
	r[prs] = '\0';
	i[0] = -1;
	while (++i[0] < (int)(prs - i[2]))
		r[i[0]] = '0';
	i[1] = -1;
	while ((*s)[++i[1]])
		r[i[0]++] = (*s)[i[1]];
	free(*s);
	return (r);
}

char	*ft_ox(u_int64_t o, int a, int b)
{
	char	*s;

	s = NULL;
	if (a == 8)
	{
		if (!(s = u_itoa_base(o, 8, 1)))
			return (NULL);
	}
	else if (a == 16)
	{
		if (!(s = (b) ? u_itoa_base(o, 16, 1) : u_itoa_base(o, 16, 0)))
			return (NULL);
	}
	else if (a == 2)
	{
		if (!(s = u_itoa_base(o, 2, 1)))
			return (NULL);
	}
	return (s);
}
