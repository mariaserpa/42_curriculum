# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 10:15:12 by mrabelo-          #+#    #+#              #
#    Updated: 2024/03/21 06:47:36 by mrabelo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

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
						game_settings.c		\
						game_draw.c			\
						sprites_settings.c)


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