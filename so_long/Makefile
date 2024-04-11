NAME = so_long

GET_NEXT_LINE_DIR = ./get_next_line
FT_PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./libft
MLX_DIR = ./mlx

LIBS = ${GET_NEXT_LINE_DIR}/libgnl.a $(FT_PRINTF_DIR)/libftprintf.a $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx_Linux.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I/usr/X11/include -Ilib/mlx
MLXFLAGS = -L/usr/X11/lib -lX11 -lXext -L./mlx -lmlx -L./libft -lft -L./ft_printf -lftprintf -L./get_next_line -lgnl -lm

RM = rm -f
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)

SRC =	$(addprefix src/, main.c 			\
						map_check_error.c 	\
						map_config.c		\
						game_settings.c		\
						game_movements.c	\
						game_draw.c			\
						map_free.c			\
						utils.c				\
						check.c				\
						sprites_settings.c)


OBJ = ${SRC:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	@make -C $(GET_NEXT_LINE_DIR)
	@make -C $(FT_PRINTF_DIR)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	${CC} $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS) $(MLXFLAGS)

clean:
	${RM} ${OBJ}
	$(RM) main/*.o
	$(RM) mlx/obj/*.o  libft/*.o ft_printf/*.o gnl/*.o

fclean: clean
	${RM} ${NAME}
	@cd $(GET_NEXT_LINE_DIR) && $(MAKE) clean
	@cd $(FT_PRINTF_DIR) && $(MAKE) clean
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@cd $(MLX_DIR) && $(MAKE) clean
	$(RM) mlx/libmlx_Linux.a libft/libft.a ft_printf/libftprintf.a gnl/libgnl.a

re: fclean all

.PHONY: clean fclean re all
