/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:33:38 by mbodak            #+#    #+#             */
/*   Updated: 2016/12/18 17:25:21 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cw(char const *s, char c, size_t *index, size_t *k)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	*index = 0;
	*k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**r;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s || !(r = (char **)malloc(sizeof(char *) * (cw(s, c, &i, &k) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] && s[i] != c)
			{
				j++;
				i++;
			}
			r[k] = ft_strsub(s, i - j, j);
			k++;
		}
		else
			i++;
	}
	r[k] = NULL;
	return (r);
}
