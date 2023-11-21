NAME = libft.a
SRC =	./ft_isalnum.c		\
	./ft_isalpha.c		\
	./ft_isascii.c		\
	./ft_isdigit.c		\
	./ft_isprint.c		\
	./ft_strlen.c		\
	./ft_toupper.c		\
	./ft_tolower.c		\
	./ft_memset.c		\
	./ft_bzero.c		\
	./ft_memcpy.c		\
	./ft_memmove.c		\
	./ft_strlcpy.c		\
	./ft_strlcat.c		\
	./ft_strncmp.c		\
	./ft_strchr.c		\
	./ft_strrchr.c		\
	./ft_memchr.c		\
	./ft_memcmp.c		\
	./ft_strnstr.c		\
	./ft_atoi.c			\
	./ft_strdup.c		\
	./ft_calloc.c		\

OBJS = $(SRC:.c=.o)

HDRS = libft.h
all: $(NAME)

$(NAME):
	cc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
