NAME = BraiiiiiiinnnzzzZ

CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CPP) $(CFLAGS) -c $< -o $@
	@echo "Done ✓"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "Executable removed!"

re: fclean all
.PHONY: all clean fclean re