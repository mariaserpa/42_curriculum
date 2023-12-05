NAME = libftprintf.a

SRC =	$(addsuffix .c, )

OBJS := $(SRC:%.c=%.o)

HEADER = ft_printf.h

INC_DIR = .
CC = cc
CCFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(INC_DIR)

RM = rm -f
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)


all: $(NAME)

$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)
	$(RANNAME)

%.o: %.c
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
