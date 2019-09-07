# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huller <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/05 20:42:10 by huller            #+#    #+#              #
#    Updated: 2019/08/06 23:31:35 by huller           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRN         =   \x1B[32m
MAG         =   \x1B[35m
RES         =   \x1B[0m


NAME            =   libftprintf.a

# PRINTF
SRC_PATH        =   srcs/
OBJ_PATH        =   srcs/obj/
INC_PATH        =   includes/

# LIBFT
LIB_PATH        =   libft/
LIB_INC_PATH    =   libft/includes/

# PRINTF
SRC_NAME        =   ft_itoa_fp.c mexp.c str_ad.c e_zrs.c ft_ox.c pw.c str_ml.c\
	fld_edge.c ft_p.c pw_to_str.c t_str.c fr_p.c ft_printf.c reader.c wzrs.c\
	ft_c.c res_o_fr.c zrs.c ft_e.c ft_round.c rnd.c add_z.c int_p.c\
	rnd_z.c apply_flags.c ft_fld.c rndg.c ft_g.c rndg_z.c c_str.c mantis.c\
	ft_itoa_base.c s_str.c ft_rg.c res_w_fr.c ft_put_percent.c chck_xu.c\
	chck_x.c chck_sr.c chck_p.c chck_o.c chck_g.c chck_f.c chck_e.c	chck_di.c\
	chck_c.c chck_b.c chck_u.c ft_u.c ft_s.c ft_free_output.c ft_bufjoin.c\
	ft_put_out.c ft_solver.c ft_app_d_prs.c ft_add_pl.c ft_solver.c\
	ft_app_width.c ft_app_fl.c ft_cycle6.c

OBJ_NAME        =   $(SRC_NAME:.c=.o)
INC_NAME        =   ft_printf.h

# LIBFT
LIB_NAME        =   libft.a
LIB_INC_NAME    =   libft.h

# PRINTF
SRC             =   $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ             =   $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC             =   $(addprefix $(INC_PATH), $(INC_NAME))

# LIBFT
LIB             =   $(addprefix $(LIB_PATH), $(LIB_NAME))
LIB_INC         =   $(addprefix $(LIB_INC_PATH), $(LIB_INC_NAME))

.PHONY:             all $(LIB_NAME) clean fclean re


all:                $(NAME)

# PRINTF
$(NAME):		$(LIB_NAME)	$(OBJ)
	@cp $(LIB) $(NAME)
	@ar r $(NAME) $(OBJ)
	@echo "$(GRN)\nPRINTF IS READY!$(RES)"

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c $(INC) $(LIB_INC)
	@mkdir -p $(OBJ_PATH)
	@gcc -Wall -Wextra -Wextra \
		-I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
	@echo -n .

# LIBFT
$(LIB_NAME):
	@make -C $(LIB_PATH)

clean:
	@make -C $(LIB_PATH) fclean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "$(MAG)Delete [ $(NAME) ] OK$(RES)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(MAG)Delete [ $(NAME) ] OK$(RES)"

re: fclean all
