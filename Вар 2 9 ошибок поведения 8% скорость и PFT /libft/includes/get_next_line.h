/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:34:05 by huller            #+#    #+#             */
/*   Updated: 2019/06/04 19:56:09 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 15
# define MAX_FD_COUNT 10240

# define ENDL '\n'
# define ERROR -1
# define END_FFILE 0
# define RD_LINE 1
# define FALSE -1

int		get_next_line(const int fd, char **line);

#endif
