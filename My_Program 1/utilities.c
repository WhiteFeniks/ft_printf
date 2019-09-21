/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:13:24 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/13 15:58:17 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itobase(ULL nb, char *base)
{
	char	*n;
	int		i;
	int		len;
	ULL		t;

	i = nb == 0 ? 1 : 0;
	len = ft_strlen(base);
	t = nb;
	while (t)
	{
		i++;
		t /= len;
	}
	if (!(n = malloc(i + 1 * sizeof(char))))
		return (NULL);
	n[i--] = '\0';
	if (nb == 0)
		n[i] = '0';
	while (nb)
	{
		n[i--] = base[nb % len];
		nb /= len;
	}
	return (n);
}

char	*ft_s_itobase(LL nb, char *base)
{
	char	*n;
	int		i;
	int		len;
	ULL		t;

	i = nb >= 0 ? 1 : 2;
	len = ft_strlen(base);
	t = nb < 0 ? -(nb + 1) + 1 : nb;
	while (nb /= len)
		i++;
	if (!(n = malloc(i + 1 * sizeof(char))))
		return (NULL);
	n[i--] = '\0';
	if (t == 0)
		n[i] = '0';
	while (t)
	{
		n[i--] = base[t % len];
		t /= len;
	}
	if (i == 0 && n[0] != '0')
		n[0] = '-';
	return (n);
}

void	ft_init_info(t_info *info)    // заполняем поля стркутуры info
{
	info->prc = -2;
	info->fields = -2;
	info->sign = 0;
	info->minus = 0;
	info->space = 0;
	info->diaz = 0;
	info->fill = ' ';
	info->flag = NULL;
	info->cur_f = '\0';
	info->index = 0;
	info->nb_p = 0;
	info->str = ft_strdup("");
}

void	ft_reset_info(t_info *info)  // очищаем структуру info к начальному виду  кроме поля index и nb_p
{
	info->prc = -2;
	info->fields = -2;
	info->sign = 0;
	info->minus = 0;
	info->space = 0;
	info->diaz = 0;
	info->fill = ' ';
	info->flag = NULL;
	info->cur_f = '\0';
}

int		ft_val(LL a)
{
	if (a >= 0)
		return (a);
	else
		return (0);
}
