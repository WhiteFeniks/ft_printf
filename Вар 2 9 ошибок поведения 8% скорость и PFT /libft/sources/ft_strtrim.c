/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:02:09 by huller            #+#    #+#             */
/*   Updated: 2019/06/14 15:11:05 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*p;
	int		len;

	if (!s)
		return (0);
	i = -1;
	j = 0;
	len = ft_strlen(s);
	while (s[len - 1] == '\n' || s[len - 1] == ' ' || s[len - 1] == '\t')
		len--;
	while (s[++i] == '\n' || s[i] == ' ' || s[i] == '\t')
		len--;
	if (len <= 0)
		len = 0;
	p = ((char *)malloc(sizeof(char) * (len + 1)));
	if (p == 0)
		return (0);
	while (len-- > 0)
		p[j++] = s[i++];
	p[j++] = '\0';
	return (p);
}
