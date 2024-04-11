/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:39:23 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/09 15:10:35 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WINDOW_H 500 //retirar
# define WINDOW_W 500 //retirar
# define WINDOW_NAME "so_long"
# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'
# define CHECKED 'R'
# define BOOL
# define TRUE 1
# define FALSE 0
# ifndef SIZE
#  define SIZE 50
# endif

# include "../mlx/mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "structures.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>

int		check_map_name(char*str);
int		check_character(int c);
int		check_boundaries(t_vars*vars, int pos_y, int pos_x);
void	check_exit(t_vars*vars);
void	check_collectibles(t_vars*vars);

void	render(t_vars*vars);
void	draw_background(t_vars *vars, int i, int j);
void	draw_player(t_vars*vars, int i, int j);
void	draw_collectibles(t_vars*vars, int i, int j);
void	draw_exit(t_vars*vars, int i, int j);

void	first_update(t_vars*vars);
void	update_up(t_vars *vars);
void	update_down(t_vars*vars);
void	update_left(t_vars*vars);
void	update_right(t_vars*vars);

void	start_param_game(t_vars*vars, char*map_path);
void	set_param_game(t_vars*vars, int c, int i, int j);
int		key_board(int keycode, t_vars*vars);

void	check_map_components(t_vars *vars);
int		check_wall(t_vars *vars);
void	check_map(t_vars*vars);
void	final_check(t_vars*vars);
void	map_solvable(t_vars*vars, t_pos start_pos);

void	parse_map(t_vars*vars);
void	map_store(t_vars*vars);
void	map_copy(t_vars*vars);
void	validate_map(t_vars*vars);
void	path_validate(t_vars*vars);

void	treat_map_error(t_vars*vars, char*str);
void	treat_read_error(t_vars*vars, char*str);
void	free_double_pointer(char**str);
void	free_pointer(char *str);
int		close_window(t_vars*vars);

void	load_xpm(t_vars*vars);
void	load_img(t_vars*vars, int x, int y);
void	img_control(t_vars*vars);
int		move_screen_counter(t_vars *vars);

int		ft_strcmp(char*s1, char*s2);
int		ft_len_newline(char*str);
void	print_error(char*str);

#endif
