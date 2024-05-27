# Executable names
NAME = pipex
NAME_BONUS = pipex_bonus

# Directories
GET_NEXT_LINE_DIR = ./get_next_line
LIBFT_DIR = ./libft
HEADERS_DIR = ./headers

# Libraries
LIBS = ${GET_NEXT_LINE_DIR}/libgnl.a $(LIBFT_DIR)/libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_DIR) -I$(GET_NEXT_LINE_DIR)

# Remove command
RM = rm -f

# Source files
SRC = $(addprefix src/, main.c exec_command.c process.c)
SRC_BONUS = $(addprefix src/, main_bonus.c cases_bonus.c exec_command_bonus.c exec_command.c)

# Object files
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

# Compilation rule for .c to .o
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Default target
all: ${NAME}

# Linking mandatory target
${NAME}: ${OBJ}
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/libft.a -o $(NAME)

# Linking bonus target
bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJ_BONUS}
	@make -C $(GET_NEXT_LINE_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBS) -o $(NAME_BONUS)

# Clean object files
clean:
	@${RM} ${OBJ} ${OBJ_BONUS}
	@make -C $(LIBFT_DIR) clean
	@make -C $(GET_NEXT_LINE_DIR) clean

# Full clean including executables and libraries
fclean: clean
	@${RM} ${NAME} ${NAME_BONUS}
	@make -C $(LIBFT_DIR) fclean
	@make -C $(GET_NEXT_LINE_DIR) fclean

# Rebuild everything
re: fclean all

# Rebuild bonus
re_bonus: fclean bonus

# Phony targets
.PHONY: clean fclean re all re_bonus bonus
