NAME = libft.a

SRC =	$(addsuffix .c, ft_isalnum	\
						ft_isalpha	\
						ft_isascii	\
						ft_isdigit	\
						ft_isprint	\
						ft_strlen	\
						ft_toupper	\
						ft_tolower	\
						ft_memset	\
						ft_bzero	\
						ft_memcpy	\
						ft_memmove	\
						ft_strlcpy	\
						ft_strlcat	\
						ft_strncmp	\
						ft_strchr	\
						ft_strrchr	\
						ft_memchr	\
						ft_memcmp	\
						ft_strnstr	\
						ft_atoi		\
						ft_strdup	\
						ft_calloc	\
						ft_substr	\
						ft_strjoin	\
						ft_strtrim)

OBJS := $(SRC:%.c=%.o)

HEADER = libft.h

INC_DIR = .
CC = cc
CCFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(INC_DIR)

RM = rm -f
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)

OBJS_ALL = $(OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)
	$(RANNAME)

%.o: %.c
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS_ALL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

everything: $(OBJS_ALL)
	$(ARNAME) $(OBJS_ALL)
	$(RANNAME)
