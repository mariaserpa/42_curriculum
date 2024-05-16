NAME = checker

LIBFT_DIR = ../push_swap/libft
PUSH_SWAP_DIR = ../push_swap

LIBS = -L$(LIBFT_DIR) -lft -L$(PUSH_SWAP_DIR) -lpush_swap

CC = @cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = main_checker.c get_next_line.c get_next_line_utils.c

OBJ = ${SRC:.c=.o}


all: ${NAME}

${NAME}: ${OBJ}
	@echo "Compiling..." 
	@make bonus -C $(LIBFT_DIR)
	@make -C $(PUSH_SWAP_DIR) libpush_swap
	@${CC} $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Done!"

clean:
	@echo "Cleaning..."
	@${RM} ${OBJ}
	@$(RM) main/*.o
	@$(RM) libft/*.o
	@$(RM) push_swap/*.o
	@echo "Done!"

fclean: clean
	@echo "Full cleaning..."
	@${RM} ${NAME}
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PUSH_SWAP_DIR) fclean
	@echo "Done!"

re: fclean all

.PHONY: clean fclean re all
