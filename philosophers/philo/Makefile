# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-los <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 01:35:08 by sede-los          #+#    #+#              #
#    Updated: 2024/11/21 01:35:09 by sede-los         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3
RM = rm -rf

SRCS = src/main.c \
		src/checker.c \
		src/error_handler.c \
		src/init.c \
		src/launcher.c \
		src/utils.c \
		src/utils_2.c \

OBJS = $(SRCS:.c=.o)

#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re