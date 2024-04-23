NAME = pipex

#GET_NEXT_LINE_DIR = ./get_next_line
#FT_PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./libft
MLX_DIR = ./mlx

#LIBS = ${GET_NEXT_LINE_DIR}/libgnl.a $(FT_PRINTF_DIR)/libftprintf.a $(LIBFT_DIR)/libft.a
LIBS = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)

SRC = $(addprefix src/, main.c exec_command.c process.c)

OBJ = ${SRC:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
#	@make -C $(GET_NEXT_LINE_DIR)
#	@make -C $(FT_PRINTF_DIR)
	@make -C $(LIBFT_DIR)
	${CC} $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

clean:
	${RM} ${OBJ}
	$(RM) main/*.o
	$(RM) libft/*.o ft_printf/*.o gnl/*.o
#	$(RM) ft_printf/*.o gnl/*.o

fclean: clean
	${RM} ${NAME}
#	@cd $(GET_NEXT_LINE_DIR) && $(MAKE) clean
#	@cd $(FT_PRINTF_DIR) && $(MAKE) clean
	@cd $(LIBFT_DIR) && $(MAKE) clean
	$(RM) libft/libft.a
#	$(RM) ft_printf/libftprintf.a gnl/libgnl.a

re: fclean all

.PHONY: clean fclean re all
