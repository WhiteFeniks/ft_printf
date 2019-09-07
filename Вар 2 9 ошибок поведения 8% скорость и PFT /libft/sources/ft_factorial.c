/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:45:50 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:07:53 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_factorial(int numb)
{
	int	i;
	int	fact;

	if (numb > 12 || numb < 0)
		return (0);
	i = 1;
	fact = 1;
	while (i <= numb)
		fact = fact * i++;
	return (fact);
}
