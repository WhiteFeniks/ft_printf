/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 06:30:08 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/18 04:31:36 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	ft_set_vars(int len, int *begin, const char *str, char **words)
{
	if (len != 0)
	{
		*words = malloc(len + 1);
		ft_strncpy(*words, str + *begin, len);
		(*words)[len] = '\0';
	}
}

static	void	ft_init_var(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nb;
	int		len;
	int		begin;
	char	**words;

	if (s == NULL)
		return (NULL);
	if (!(words = ft_memalloc(1024)))
		return (NULL);
	ft_init_var(&i, &nb, &len, &begin);
	while (s[i] != '\0')
	{
		if (c == s[i])
		{
			ft_set_vars(len, &begin, s, words + (len != 0 ? nb++ : nb));
			len = 0;
			begin = i + 1;
		}
		else
			len = len + 1;
		i = i + 1;
	}
	ft_set_vars(len, &begin, s, words + (len != 0 ? nb++ : nb));
	return (words);
}
