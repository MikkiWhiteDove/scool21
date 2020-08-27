FRAEMWORKS=-framework OpenGL -framework AppKit

FLAGS=-Werror -Wextra -Wall

NAME=fdf

DIRECTORY=./src/

SRC=main.c\
draw.c\
fdf.c\
isometric.c\
key.c\
print_menu.c

SRC_DIRECTORY= $(addprefix $(DIRECTORY), $(SRC))

INCLUDES=libft/libft.a minilibx_macos/libmlx.a

all:
	@make -C libft/ all
	@make -C minilibx_macos/ all
	gcc $(SRC_DIRECTORY) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all