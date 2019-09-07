/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:56:54 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:10:55 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**returning_zero(char **array, int k)
{
	while (--k >= 0)
	{
		free(array[k]);
	}
	free(array);
	return (NULL);
}

static int		count_arrays(const char *s, char c)
{
	int i;
	int counting;

	i = 0;
	counting = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			counting++;
		}
		i++;
	}
	if (s[0] != c && s)
		counting++;
	return (counting);
}

static char		*allocate_memory(const char *str, int size, int start)
{
	char	*p;
	int		i;

	i = 0;
	if (str[start] == '\0')
		return (0);
	if (!(p = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
		p[i++] = str[start++];
	p[i] = '\0';
	return (p);
}

static char		*letter_counter(const char *str, char c, int *i)
{
	int		let;
	int		j;
	int		begin;
	char	*arr;

	let = 0;
	j = *i;
	begin = 0;
	while (str[j] == c && str[j])
		j++;
	begin = j;
	while (str[j] != c && str[j])
	{
		j++;
		let++;
	}
	arr = allocate_memory(str, let, begin);
	*i = j;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		k;
	char	**arrays;
	int		i;
	int		len;

	k = 0;
	i = 0;
	if (!s)
		return (0);
	len = count_arrays(s, c);
	if (!(arrays = (char **)malloc(sizeof(char *) * (len + 1))))
		return (0);
	while (s[i] != '\0')
	{
		arrays[k] = letter_counter(s, c, &i);
		if (arrays[k] == NULL && k != len)
			return (returning_zero(arrays, k - 1));
		k++;
	}
	arrays[len] = NULL;
	return (arrays);
}
