# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 10:15:12 by mrabelo-          #+#    #+#              #
#    Updated: 2024/02/07 10:38:48 by mrabelo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_bonus

GET_NEXT_LINE = get_next_line/*c

FT_PRINTFDIR = ./ft_printf

MLXDIR = ./mlx

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

SRC =	$(addprefix src/, main.c 			\
						map_check_error.c 	\
						map_check_utils.c	\
						map_config.c		\
						map_draw.c			\
						game_settings.c		)


OBJ = ${SRC:.c=.o}
INFT_PRINTF = -L./ft_printf -lftprintf
INMLX = -L./mlx -lmlx

.c.o:
	${CC} ${FLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJ}
	@make -C $(FT_PRINTFDIR)
	@make -C $(MLXDIR)
	${CC} ${OBJ} ${INFT_PRINTF} ${INMLX} $(GET_NEXT_LINE) -framework OpenGL -framework AppKit -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJ} 
	@cd $(FT_PRINTFDIR) && $(MAKE) clean
	@cd $(MLXDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(FT_PRINTFDIR) && $(MAKE) fclean

re: fclean all