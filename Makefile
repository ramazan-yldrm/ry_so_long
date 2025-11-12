NAME = so_long
CFLAGS = -Wall -Wextra -Werror
SRC =	main.c
OBJ = $(SRC:.c=.o)

MLXLIB = ./mlx/libmlx.a
MLXFLAGS = -L./mlx -lmlx -lXext -lX11 -lm -lbsd

GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

all: $(NAME) clean

$(NAME): $(OBJ) $(MLXLIB)
	cc $(CFLAGS) $(OBJ) $(MLXFLAGS) $(GET_NEXT_LINE) -o $(NAME)

$(MLXLIB):
	make -C ./mlx

clean:
	rm -rf $(OBJ)
	make -C ./mlx clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re