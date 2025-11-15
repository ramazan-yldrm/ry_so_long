NAME = so_long
CFLAGS = -Wall -Wextra -Werror
SRC =	src/main.c \
		src/check_arg.c \
		src/map.c
OBJ = $(SRC:.c=.o)

MLXLIB = mlx/libmlx.a
MLXFLAGS = -L./mlx -lmlx -lXext -lX11 -lm -lbsd

GET_NEXT_LINE = get_next_line/*.c
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(MLXLIB) $(LIBFT)
	cc $(CFLAGS) $(OBJ) $(MLXFLAGS) $(GET_NEXT_LINE) $(LIBFT) -o $(NAME)

$(MLXLIB):
	make -C ./mlx

$(LIBFT):
	make -C ./libft

clean:
	rm -rf $(OBJ)
	make -C ./mlx clean
	make -C ./libft clean
 
fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re