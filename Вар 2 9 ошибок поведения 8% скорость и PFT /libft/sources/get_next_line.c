/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:33:44 by huller            #+#    #+#             */
/*   Updated: 2019/06/18 14:49:25 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*stradd(char *s1, char *s2)
{
	char			*temp;

	if (!s1)
		if (!(s1 = ft_strnew(0)))
			return (NULL);
	temp = s1;
	if (!(s1 = ft_strjoin(s1, s2)))
		return (NULL);
	free((void *)temp);
	return (s1);
}

static int		check_n(const char *str)
{
	int				i;

	if (!str)
		return (FALSE);
	i = 0;
	while (str[i] && str[i] != ENDL)
		i++;
	return (str[i] == '\0' ? FALSE : i);
}

static char		*clear_buff(char *buf)
{
	int	i;
	int	rm;
	int j;

	j = ft_strlen(buf);
	if (!(i = check_n(buf) + 1))
	{
		*buf = '\0';
		return (buf);
	}
	rm = i;
	while (i != j--)
	{
		*buf = buf[i];
		buf++;
	}
	ft_bzero(buf, rm);
	return (buf);
}

static char		*create_newstr(char *src, int end)
{
	char			*result;

	if (!(result = (char *)malloc(sizeof(char) * (end + 1))))
		return (NULL);
	ft_strncpy(result, src, end);
	result[end] = '\0';
	return (result);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				bite;
	static char		*tmp[MAX_FD_COUNT];
	int				res;

	if (fd < 0 || fd >= MAX_FD_COUNT || !line)
		return (ERROR);
	while ((bite = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bite] = '\0';
		if (!(tmp[fd] = stradd(tmp[fd], buf)))
			return (ERROR);
		if (check_n(tmp[fd]) != FALSE)
			break ;
	}
	if (bite == -1)
		return (ERROR);
	res = tmp[fd] ? check_n(tmp[fd]) : 0;
	if (!(*line = create_newstr(tmp[fd],
		res != FALSE ? res : ft_strlen(tmp[fd]))))
		return (ERROR);
	if (check_n(tmp[fd]) == FALSE && !**line && !bite)
		return (END_FFILE);
	clear_buff(tmp[fd]);
	return (RD_LINE);
}
