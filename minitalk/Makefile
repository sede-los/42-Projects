# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-los <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 18:51:25 by sede-los          #+#    #+#              #
#    Updated: 2024/06/18 18:51:32 by sede-los         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SERVER = server
CLIENT = client

SERVER_SRCS = minitalk/server.c
CLIENT_SRCS = minitalk/client.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_BONUS_SRCS = minitalk_bonus/server_bonus.c
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
CLIENT_BONUS_SRCS = minitalk_bonus/client_bonus.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)


LIBFT_PATH = ./libft
PRINTF_PATH = ./printf
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

#------------------------------------------------------------------------------#

all:$(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER) $(LIBFT) $(PRINTF)
$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT) $(LIBFT) $(PRINTF)

$(SERVER_BONUS): $(SERVER_BONUS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) -o $(SERVER_BONUS) $(LIBFT) $(PRINTF)
$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) -o $(CLIENT_BONUS) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(PRINTF):
	make -C $(PRINTF_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	$(RM) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean
	$(RM) $(CLIENT) $(SERVER)
	$(RM) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

.PHONY: all clean fclean re
