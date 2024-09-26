GREEN		=		\033[0;32m
RED			=		\033[0;31m
BLACK		=		\033[0;30m
YELLOW		=		\033[1;33m
BLUE		=		\033[0;34m
PURPLE		=		\033[1;95m
END			=		\033[0m


CC			=		gcc
CFLAGS		=		-Wall -Wextra -Werror -fsanitize=address 
RM			=		rm -rf
LIBS		=		-L ./libft -l:libft.a -lreadline
LIBFT		=		./libft/libft.a


NAME		=		minishell
SRC_SRC		=	\
					debug.c \
					envp.c \
					error.c \
					main.c \
					prompt.c \
					signal.c \
					utils.c \
 
BUILT-INS_SRC		=	\
					builtins_utils.c \
					cd.c \
					echo.c \
					env.c \
					exit.c \
					export.c \
					pwd.c \
					unset.c \
 
COMMAND_SRC		=	\
					cmd_utils.c \
					command.c \
					command_utils.c \
					heredoc.c \
					redirection.c \
 
EXEC_SRC		=	\
					exec_cmds.c \
					exec_utils.c \
 
EXPAND_SRC		=	\
					expand.c \
					expand_utils.c \
 
PARSE_SRC		=	\
					lex_utils.c \
					parse.c \
					parse_utils.c \
					quotes.c \
 
SRC_FILES		=	\
					$(addprefix $(SRC_DIR)/, $(SRC_SRC)) \
					$(addprefix $(BUILT-INS_DIR)/, $(BUILT-INS_SRC)) \
					$(addprefix $(COMMAND_DIR)/, $(COMMAND_SRC)) \
					$(addprefix $(EXEC_DIR)/, $(EXEC_SRC)) \
					$(addprefix $(EXPAND_DIR)/, $(EXPAND_SRC)) \
					$(addprefix $(PARSE_DIR)/, $(PARSE_SRC)) \
 
OBJ				=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))


SRC_DIR		=	src
BUILT-INS_DIR		=	src/built-ins
COMMAND_DIR		=	src/command
EXEC_DIR		=	src/exec
EXPAND_DIR		=	src/expand
PARSE_DIR		=	src/parse
INC_DIR		=		include
OBJ_DIR		=		obj


all: $(NAME)

$(LIBFT):
	@make -s -C ./libft

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@printf "                                                 \r"
	@printf "$(GREEN)> BUILDING MINISHELL			[✓]$(END)\n"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@printf "$(YELLOW)> BUILDING $<               \r$(END)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p obj/src
	@mkdir -p obj/src/built-ins
	@mkdir -p obj/src/command
	@mkdir -p obj/src/exec
	@mkdir -p obj/src/expand
	@mkdir -p obj/src/parse

clean:
	@make clean -s -C ./libft
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make fclean -s -C ./libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re