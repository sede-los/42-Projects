# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-los <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 03:00:03 by sede-los          #+#    #+#              #
#    Updated: 2024/04/02 21:13:02 by sede-los         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LINKS = -framework OpenGL -framework AppKit
RM = rm -rf

SRCS = check_map.c \
	   errors.c \
	   so_long.c \
	   initialize.c \
	   check_border.c \
	   check_route.c \
	   exit_game.c \
	   move_player.c \
	   print_image.c \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./libft
MLX_PATH = ./mlx
PRINTF_PATH = ./printf
LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINKS) -o $(NAME) $(LIBFT) $(PRINTF) $(MLX)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(MLX):
	make -C $(MLX_PATH) all

$(PRINTF):
	make -C $(PRINTF_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	make -C $(PRINTF_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
