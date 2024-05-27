NAME	=	libgnl.a

SRC		=	get_next_line.c		\
			get_next_line_utils.c

OBJ = $(SRC:.c=.o)

HEADER = get_next_line.h

INC_DIR = .
CC		=	@cc
CFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS = -I$(INC_DIR)

RM = rm -rf
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

all: $(NAME)
$(NAME): $(OBJ)
	$(ARNAME) $(OBJ)
	$(RANNAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
