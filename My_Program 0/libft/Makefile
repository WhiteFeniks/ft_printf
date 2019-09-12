# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbodak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/17 13:39:35 by mbodak            #+#    #+#              #
#    Updated: 2017/02/03 11:23:52 by mbodak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c		\
	   ft_memchr.c  ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c		\
	   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c	\
	   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c	\
	   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c	\
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c	\
	   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c	\
	   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c	\
	   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c	\
	   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c				\
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c		\
	   ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstadd_back.c			\
	   ft_lstiter.c ft_lstmap.c ft_count_words.c ft_itoa_base.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I libft.h
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
