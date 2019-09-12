/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:32:07 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/22 15:32:13 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_join(char *str1, char *str2, t_del string)
{
	char	*final;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(str1) + ft_strlen(str2);
	if (!str1 || !str2)
		return (0);
	if (!(final = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (str1[i])
	{
		final[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		final[i++] = str2[j++];
	final[i] = '\0';
	if (string == BOTH || string == FIRST)
		free(str1);
	if (string == BOTH || string == SECOND)
		free(str2);
	return (final);
}

static char		*str_width(char *str, t_saver *saver)
{
	char	*tmp;
	int		i;

	if ((saver->width > 0) && (saver->width > (int)ft_strlen(str)))
	{
		saver->width = saver->width - (int)ft_strlen(str);
		tmp = ft_strnew((size_t)saver->width);
		i = 0;
		while (i < saver->width)
		{
			if (saver->minus_null == '0')
				tmp[i] = '0';
			else
				tmp[i] = ' ';
			i++;
		}
		tmp[i] = '\0';
		if (saver->minus_null == '-')
			str = ft_join(str, tmp, FIRST);
		else
			str = ft_join(tmp, str, SECOND);
		free(tmp);
	}
	return (str);
}

static char		*str_precision(char *str, t_saver *saver)
{
	char	*res;
	int		i;

	if ((saver->precision >= 0) && (saver->precision < (int)ft_strlen(str)))
	{
		i = 0;
		res = ft_strnew((size_t)saver->precision);
		while (i < saver->precision)
		{
			res[i] = str[i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (str);
}

void			print_string(t_saver *saver, va_list arg)
{
	char	*str;

	if (saver->size == L)
		str = convert_wstrtostr(va_arg(arg, wchar_t *), saver->precision);
	else
	{
		str = va_arg(arg, char *);
		if (!str)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(str);
	}
	str = str_precision(str, saver);
	str = str_width(str, saver);
	ft_put_string(str);
	free(str);
}
