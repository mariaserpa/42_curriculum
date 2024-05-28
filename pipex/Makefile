NAME = pipex
NAME_BONUS = pipex_bonus

GET_NEXT_LINE_DIR = ./get_next_line
LIBFT_DIR = ./libft
HEADERS_DIR = ./headers

LIBS = ${GET_NEXT_LINE_DIR}/libgnl.a $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_DIR) -I$(GET_NEXT_LINE_DIR)

RM = rm -f

SRC = $(addprefix src/, main.c exec_command.c process.c)
SRC_BONUS = bonus/main_bonus.c bonus/cases_bonus.c bonus/exec_command_bonus.c src/exec_command.c

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/libft.a -o $(NAME)

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJ_BONUS}
	@make -C $(GET_NEXT_LINE_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBS) -o $(NAME_BONUS)

clean:
	@${RM} ${OBJ} ${OBJ_BONUS}
	@make -C $(LIBFT_DIR) clean
	@make -C $(GET_NEXT_LINE_DIR) clean

fclean: clean
	@${RM} ${NAME} ${NAME_BONUS}
	@make -C $(LIBFT_DIR) fclean
	@make -C $(GET_NEXT_LINE_DIR) fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: clean fclean re all re_bonus bonus
