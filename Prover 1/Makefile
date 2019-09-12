# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:44:21 by yez-zain          #+#    #+#              #
#    Updated: 2019/02/13 13:07:10 by yez-zain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c parse.c process_bases.c process_real.c process_int.c process_str.c tools.c utilities.c real.c t_big_int.c advanced_tools.c big_int_tools.c libft/*.c
OBJ = ft_printf.o parse.o process_bases.o process_real.o process_int.o process_str.o tools.o utilities.o real.o t_big_int.o advanced_tools.o big_int_tools.o libft/*.o
LIBFT = libft/libft.a
all: $(NAME)

$(NAME):
	@make -C libft
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJ) $(LIBFT)
	@ranlib $(NAME)
clean:
	@make -C libft clean
	@/bin/rm -f *.o

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all
