/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:09:32 by yez-zain          #+#    #+#             */
/*   Updated: 2019/02/09 23:02:29 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_charjoin(char *str, char c)
{
	char	*new;
	char	s[2];
	int		len;

	s[0] = 'a';
	s[1] = '\0';
	len = ft_strlen(str);
	new = ft_strjoin(str, s);
	new[len] = c;
	free(str);
	return (new);
}

char	*g_strjoin(char *str, char *s, int free_str)
{
	char	*new;

	new = ft_strjoin(str, s);
	free(str);
	if (free_str)
		free(s);
	return (new);
}

int		char_in(char c, char *str)
{
	int		i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_nb_digit(LL nb)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*str_gen(char c, int len)
{
	char	*str;

	if (len <= 0)
		return (ft_strdup(""));
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_memset(str, c, len);
	str[len] = '\0';
	return (str);
}
