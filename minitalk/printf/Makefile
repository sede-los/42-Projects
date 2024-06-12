NAME = libftprintf.a
SOURCES =	\
			ft_printf.c ft_printchr.c ft_printnbr.c ft_printhexmay.c ft_printptr.c \
			ft_printstr.c ft_printunsnbr.c ft_printhex.c
OBJECTS = $(SOURCES:.c=.o)

AR = ar

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
		$(AR) rcs $@ $?

%.o: %.c
		$(CC) -c $(CFLAGS) $?

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
