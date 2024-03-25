/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:39:23 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/03/21 10:56:16 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WINDOW_H 500
# define WINDOW_W 500
# define WINDOW_NAME "so_long"
# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'
# define BOOL short int
# define TRUE 1
# define FALSE 0
# ifndef SIZE
#  define SIZE 50
# endif

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "structures.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

int		render(t_vars*vars);
void	background_draw(t_vars*vars);
void	map_draw(t_vars*vars);
void	moves_display(t_vars*vars);
void	map_sprite_to_window(t_vars*vars, t_pos g_pos, char g_value);

void	start_param_game(t_vars*vars, char*map_path);
void	start_map(t_vars*vars, t_pos*grid_pos);
int		close_window(t_vars*vars);
int		key_board(int keycode, t_vars*vars);
void	update_position(t_vars*vars, t_pos grid_pos);

int		check_map_name(char*str);
int		check_character(int c);
void	check_param_game(t_vars*vars, char c, t_pos pos);
int		check_wall(t_vars*vars);
void	check_map(t_vars*vars);

int		ft_strcmp(char*s1, char*s2);
size_t	ft_newline_len(char*str);
void	print_error(char*str);
void	free_tiles(t_vars *vars);

int		parse_map(t_map*map);
void	malloc_line(t_vars*vars, t_pos grid_pos);
void	fill_tile(t_vars*vars, char*line, t_pos grid_pos);
void	map_solvable(t_vars*vars, t_pos grid_pos);
int		fill_grid(t_vars*vars);

void	load_sprites(t_vars*vars);
void	load_qt_move_display(t_vars*vars);

#endif