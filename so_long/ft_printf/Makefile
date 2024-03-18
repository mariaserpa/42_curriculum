NAME = libftprintf.a

SRC = ft_printf.c
SRC_PRINTERS = $(addprefix printers/, ft_print_char.c				\
										ft_print_pointer.c			\
										ft_print_sign_dec_int.c		\
										ft_print_str.c				\
										ft_print_unsign_dec_int.c	\
										ft_print_unsign_hex_int.c)
SRC_OPERATORS = $(addprefix printers/operators/, ft_putnbr_base.c 			\
													ft_putnbr_hex_base.c	\
													ft_putnbr_unsign.c		\
													ft_strlen.c)

OBJS := $(SRC:%.c=%.o)
OBJS_PRINTERS := $(SRC_PRINTERS:%.c=%.o)
OBJS_OPERATORS := $(SRC_OPERATORS:%.c=%.o)

HEADER = ft_printf.h

INC_DIR = .
CC = clang
CCFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(INC_DIR)

RM = rm -f
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<


all: $(NAME)
$(NAME): $(OBJS) $(OBJS_PRINTERS) $(OBJS_OPERATORS)
	$(ARNAME) $(OBJS) $(OBJS_PRINTERS) $(OBJS_OPERATORS)
	$(RANNAME)

clean:
	$(RM) $(OBJS) $(OBJS_PRINTERS) $(OBJS_OPERATORS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
