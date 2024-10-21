NAME = philo

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -pthread
RM		= rm -rf

# Paths
OBJDIR = ./objects
SRCDIR = ./src
HEADERS_DIR = ./includes

# Soure files
SRC = $(SRCDIR)/actions.c $(SRCDIR)/free_exit.c $(SRCDIR)/init.c \
	$(SRCDIR)/main.c $(SRCDIR)/routine.c $(SRCDIR)/utils.c 

# List of headers
HEADERS = $(HEADERS_DIR)/philo.h

# Object files
OBJS = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

# Building executables
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I$(HEADERS_DIR) -o $(NAME) 2>/dev/null
	@echo "\033[32;1mCompiled\033[5m ✓ \033[0m"

# Compilation rule for object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleanup
clean:
	@$(RM) $(OBJDIR)
	@echo "\033[37;1mObject files removed.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[37;1mExecutable removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re
