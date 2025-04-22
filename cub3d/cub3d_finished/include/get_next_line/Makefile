# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 17:16:48 by isainz-r          #+#    #+#              #
#    Updated: 2024/05/14 16:12:36 by isainz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = gnl.a
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
AR      = ar
ARFLAGS = -rcs

SRCS	= get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
