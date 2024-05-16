NAME = libft.a

SRC =	$(addsuffix .c, ft_isalnum			\
						ft_isalpha			\
						ft_isascii			\
						ft_isdigit			\
						ft_isprint			\
						ft_strlen			\
						ft_toupper			\
						ft_tolower			\
						ft_memset			\
						ft_bzero			\
						ft_memcpy			\
						ft_memmove			\
						ft_strlcpy			\
						ft_strlcat			\
						ft_strcmp			\
						ft_strncmp			\
						ft_strchr			\
						ft_strrchr			\
						ft_memchr			\
						ft_memcmp			\
						ft_strnstr			\
						ft_atoi				\
						ft_atol				\
						ft_strdup			\
						ft_calloc			\
						ft_substr			\
						ft_strjoin			\
						ft_strtrim			\
						ft_split			\
						ft_split_mod		\
						ft_putchar_fd		\
						ft_putstr_fd		\
						ft_putnbr_fd		\
						ft_putendl_fd		\
						ft_itoa				\
						ft_strmapi			\
						ft_striteri)

BONUS_SRC = $(addsuffix .c, ft_lstnew		\
							ft_lstadd_front	\
							ft_lstsize		\
							ft_lst_last		\
							ft_lstadd_back	\
							ft_lstdelone	\
							ft_lstclear		\
							ft_lstiter		\
							ft_lstmap)

OBJS := $(SRC:%.c=%.o)

BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

HEADER = libft.h

INC_DIR = .
CC = cc
CCFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(INC_DIR)

RM = rm -f
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)

OBJS_ALL = $(OBJS) $(BONUS_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	@$(ARNAME) $(OBJS)
	@$(RANNAME)

%.o: %.c
	@$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS_ALL)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

bonus: $(OBJS_ALL)
	@$(ARNAME) $(OBJS_ALL)
	@$(RANNAME)
