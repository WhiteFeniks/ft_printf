/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_width_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:30:18 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/22 15:30:26 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*check_start_str(t_saver *saver, char *str, char *tmp)
{
	char	*res;

	if (str[0] == '-')
		res = ft_join(ft_strjoin("-", tmp), str + 1, FIRST);
	else if (saver->specifier == 'o' && saver->hash == '#')
		res = ft_strjoin(tmp, str + 1);
	else if (str[1] == 'x')
		res = ft_join(ft_strjoin("0x", tmp), str + 2, FIRST);
	else if (str[1] == 'X')
		res = ft_join(ft_strjoin("0X", tmp), str + 2, FIRST);
	else if (str[1] == 'b')
		res = ft_join(ft_strjoin("0b", tmp), str + 2, FIRST);
	else
		res = ft_strjoin(tmp, str);
	return (res);
}

char			*add_precision(t_saver *saver, char *str)
{
	char	*tmp;
	char	*res;
	size_t	len;
	size_t	size;
	size_t	i;

	len = ft_strlen(str);
	if (str[0] == '-' || (saver->specifier == 'o' && saver->hash == '#'))
		len = ft_strlen(str) - 1;
	else if (str[1] == 'x' || str[1] == 'X' || str[1] == 'b')
		len = ft_strlen(str) - 2;
	if (saver->precision > (int)len)
	{
		i = 0;
		size = (size_t)saver->precision - len;
		tmp = ft_strnew(size + 1);
		while (i < size)
			tmp[i++] = '0';
		tmp[i] = '\0';
		res = check_start_str(saver, str, tmp);
		free(tmp);
		free(str);
		return (res);
	}
	return (str);
}

char			*add_flags(t_saver *saver, char *str)
{
	char	*res;

	if (saver->plus_space == '+' && !ft_strchr(str, '-'))
	{
		res = ft_strjoin("+", str);
		free(str);
	}
	else if (saver->plus_space == ' ' && !ft_strchr(str, '-'))
	{
		res = ft_strjoin(" ", str);
		free(str);
	}
	else
		res = str;
	return (res);
}

static char		*check_flag_null(char *str, char *tmp)
{
	char	*res;

	if (str[0] == ' ')
		res = ft_join(ft_strjoin(" ", tmp), str + 1, FIRST);
	else if (str[0] == '-')
		res = ft_join(ft_strjoin("-", tmp), str + 1, FIRST);
	else if (str[0] == '+')
		res = ft_join(ft_strjoin("+", tmp), str + 1, FIRST);
	else if (str[1] == 'x')
		res = ft_join(ft_strjoin("0x", tmp), str + 2, FIRST);
	else if (str[1] == 'X')
		res = ft_join(ft_strjoin("0X", tmp), str + 2, FIRST);
	else if (str[1] == 'b')
		res = ft_join(ft_strjoin("0b", tmp), str + 2, FIRST);
	else
		res = ft_strjoin(tmp, str);
	return (res);
}

char			*add_min_width(t_saver *saver, char *str)
{
	char	*tmp;
	char	*res;

	if ((saver->width > 0) && (saver->width > (int)ft_strlen(str)))
	{
		saver->width = saver->width - (int)ft_strlen(str);
		tmp = ft_strnew((size_t)saver->width);
		if (saver->minus_null == '0' && saver->precision < 0)
			tmp = ft_memset(tmp, '0', (size_t)saver->width);
		else
			tmp = ft_memset(tmp, ' ', (size_t)saver->width);
		if (saver->minus_null == '0')
			res = check_flag_null(str, tmp);
		else if (saver->minus_null == '-')
			res = ft_strjoin(str, tmp);
		else
			res = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
		return (res);
	}
	return (str);
}
