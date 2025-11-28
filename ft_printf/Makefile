NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_puthex.c \
		ft_putnbr.c \
		ft_putnbr_unsig.c \
		ft_puthexlow.c \
		ft_puthexup.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
