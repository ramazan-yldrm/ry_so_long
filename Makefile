NAME = so_long
MLXLIB = mlx/libmlx.a
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L./mlx -lmlx -lXext -lX11 -lm -lbsd
SRC =	src/main.c \
		src/check_map.c \
		src/draw_map.c \
		src/read_map.c	\
		src/moves.c \
		src/utils.c \
		src/floodfill.c \
		get_next_line/get_next_line.c \
        get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLXLIB) $(LIBFT)
	cc $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)

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