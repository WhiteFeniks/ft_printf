/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_big_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:29:23 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/12 00:10:46 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_BIG_TYPES_H
# define T_BIG_TYPES_H

typedef struct	s_big_int
{
	char		*value;
	int			size;
}				t_big_int;

void			free_big_int(t_big_int *a);

t_big_int		*big_int(char *value, int is_freed, int reverse);

t_big_int		*t_big_int_add(t_big_int *a, t_big_int *b, int bfree);

t_big_int		*t_big_int_mul(t_big_int *a, t_big_int *b, int bfree);

t_big_int		*t_big_int_pow(t_big_int *a, int b, int is_freed);

#endif
