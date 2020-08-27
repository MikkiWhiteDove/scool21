# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 00:14:46 by sreyne            #+#    #+#              #
#    Updated: 2020/07/03 01:26:42 by sreyne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

FLAGS	= -Wall -Wextra -Werror

FRAEM	= -framework OpenGL -framework AppKit

SRC_DIR	= ./src/
OBJ		= ./obj/


S_NAME	= main.c\
		 fractols.c\
		 mandelbrot.c\
		 chameleon.c\
		 julia.c\
		 key_hook.c\
		 mouse_hook.c

SRC		= $(addprefix $(SRC_DIR), $(S_NAME))

INC		= libft/libft.a minilibx_macos/libmlx.a

all:
		@make -C libft/ all
		@make -C minilibx_macos/ all
		gcc $(SRC) -o $(NAME) $(FLAGS) $(INC) $(FRAEM)

clean:
		@make -C libft/ clean
		@make -C minilibx_macos/ clean

fclean: clean
		/bin/rm -f $(NAME)
		@make -C libft/ fclean

re: 	fclean all
