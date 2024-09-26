GREEN		=		\033[0;32m
RED			=		\033[0;31m
BLACK		=		\033[0;30m
YELLOW		=		\033[1;33m
BLUE		=		\033[0;34m
PURPLE		=		\033[1;95m
END			=		\033[0m


CC			=		gcc
CFLAGS		=		-Wall -Wextra -Werror
RM			=		rm -rf


NAME		=		libft.a
SRC_SRC		=	\
 
CUSTOM_SRC		=	\
					ft_strapp.c \
					ft_strnapp.c \
 
FT_FPRINTF_SRC		=	\
					fexlibft.c \
					ft_fprintaddr.c \
					ft_fprintchar.c \
					ft_fprintf.c \
					ft_fprinthex.c \
					ft_fprintint.c \
					ft_fprintstr.c \
					ft_fprintuint.c \
					futils.c \
 
FT_PRINTF_SRC		=	\
					exlibft.c \
					format_utils.c \
					ft_printaddr.c \
					ft_printchar.c \
					ft_printf.c \
					ft_printhex.c \
					ft_printint.c \
					ft_printstr.c \
					ft_printuint.c \
					utils.c \
 
GNL_SRC		=	\
					get_next_line.c \
					get_next_line_utils.c \
 
LEGACY_SRC		=	\
					ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstsize.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c \
 
SRC_FILES		=	\
					$(addprefix $(SRC_DIR)/, $(SRC_SRC)) \
					$(addprefix $(CUSTOM_DIR)/, $(CUSTOM_SRC)) \
					$(addprefix $(FT_FPRINTF_DIR)/, $(FT_FPRINTF_SRC)) \
					$(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_SRC)) \
					$(addprefix $(GNL_DIR)/, $(GNL_SRC)) \
					$(addprefix $(LEGACY_DIR)/, $(LEGACY_SRC)) \
 
OBJ				=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))


SRC_DIR		=	src
CUSTOM_DIR		=	src/custom
FT_FPRINTF_DIR		=	src/ft_fprintf
FT_PRINTF_DIR		=	src/ft_printf
GNL_DIR		=	src/gnl
LEGACY_DIR		=	src/legacy
INC_DIR		=		include
OBJ_DIR		=		obj


all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "                                   \r"
	@printf "$(GREEN)> BUILDING LIBFT			[✓]$(END)\n"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@printf "$(YELLOW)> BUILDING $<               \r$(END)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p obj/src
	@mkdir -p obj/src/custom
	@mkdir -p obj/src/ft_fprintf
	@mkdir -p obj/src/ft_printf
	@mkdir -p obj/src/gnl
	@mkdir -p obj/src/legacy

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re