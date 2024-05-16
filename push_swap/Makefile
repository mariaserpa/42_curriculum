NAME = push_swap

LIBFT_DIR = ./libft

LIBS = $(LIBFT_DIR)/libft.a

CC = @cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)
LIBNAME	= libpush_swap.a

SRC = $(addprefix src/, main.c				\
						error.c 			\
						free.c				\
						sort.c				\
						sort_utils_check.c	\
						sort_utils_prep.c	\
						sort_utils_push.c	\
						stack.c				\
						command_swap.c		\
						command_push.c		\
						command_reverse.c	\
						command_rotate.c	)

OBJ = ${SRC:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	@echo "Compiling..." 
	@make bonus -C $(LIBFT_DIR)
	@${CC} $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Done!"

clean:
	@echo "Cleaning..."
	@${RM} ${OBJ}
	@$(RM) main/*.o
	@$(RM) libft/*.o
	@echo "Done!"

fclean: clean
	@echo "Full cleaning..."
	@${RM} ${NAME}
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@$(RM) libft/libft.a
	@echo "Done!"

re: fclean all

.PHONY: clean fclean re all
