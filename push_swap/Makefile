# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-los <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 19:22:11 by sede-los          #+#    #+#              #
#    Updated: 2024/05/28 19:22:15 by sede-los         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = check_sorted.c \
	   ft_add_back.c \
	   ft_check_dup.c \
	   ft_error.c \
	   ft_free.c \
	   ft_new_stack.c \
	   ft_process.c \
	   ft_rotate_and_push.c \
	   ft_rotation_type.c \
	   operations.c \
	   operations_2.c \
	   operations_3.c \
	   push_swap.c \
	   rotation_utils_ab.c \
	   rotation_utils_ba.c \
	   sort.c \
	   utils.c \
	   utils_2.c \

OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./libft
PRINTF_PATH = ./printf
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(PRINTF):
	make -C $(PRINTF_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re