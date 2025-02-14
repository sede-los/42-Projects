NAME = game 
CC = cc
OBJ = $(SRC:.c=.o)

LFLAGS = -L./includes/mlx -lmlx -lXext -lX11 -lm -lz
INCLUDES = includes/mlx/libmlx.a
SRC = src/main.c src/player.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(INCLUDES) $(LFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re