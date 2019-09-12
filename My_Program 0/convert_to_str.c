/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:43:45 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/22 21:43:48 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*generate_wint(wint_t wint, int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len--] = '\0';
	if (len == 0)
	{
		str[len] = (char)wint;
		return (str);
	}
	str[len--] = (char)((wint & 63) + 128);
	if (len == 0)
	{
		str[len] = (char)(((wint & 1984) >> 6) + 192);
		return (str);
	}
	str[len--] = (char)(((wint & 4032) >> 6) + 128);
	if (len == 0)
	{
		str[len] = (char)(((wint & 61440) >> 12) + 224);
		return (str);
	}
	str[len--] = (char)(((wint & 258048) >> 12) + 128);
	str[len] = (char)(((wint & 1835008) >> 18) + 240);
	return (str);
}

static char		*convert_winttostr(wint_t wint)
{
	if (wint < 128)
		return (generate_wint(wint, 1));
	if (wint < 2048)
		return (generate_wint(wint, 2));
	if (wint < 65536)
		return (generate_wint(wint, 3));
	if (wint < 1114112)
		return (generate_wint(wint, 4));
	return (NULL);
}

char			*convert_wstrtostr(wchar_t *str, int max_len)
{
	char	*wint_tmp;
	char	*tmp;
	char	*final;
	size_t	size;

	if (!str)
		return (ft_strdup("(null)"));
	size = 0;
	final = ft_strdup("");
	while (str[size])
	{
		tmp = final;
		wint_tmp = convert_winttostr(str[size]);
		final = ft_strjoin(final, wint_tmp);
		free(wint_tmp);
		if (max_len >= 0 && (int)ft_strlen(final) > max_len)
		{
			free(final);
			final = tmp;
			break ;
		}
		free(tmp);
		size++;
	}
	return (final);
}
