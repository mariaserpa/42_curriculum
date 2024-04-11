/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:28:41 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/09 15:09:56 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	start_param_game(t_vars*vars, char*map_path)
{
	vars->map.map_path = map_path;
	vars->mlx = NULL;
	vars->mlx_win = NULL;
	vars->img = (t_img){NULL, NULL, NULL, NULL, NULL, \
						NULL, NULL, NULL, NULL, NULL};
	vars->map.map = NULL;
	vars->map.map_copy = NULL;
	vars->counts.qt_player = 0;
	vars->counts.qt_collectibles = 0;
	vars->counts.qt_exit = 0;
	vars->player.pos_x = 0;
	vars->player.pos_y = 0;
	vars->map.display.pos_x = 0;
	vars->map.display.pos_y = 0;
	vars->map.exit.pos_x = 0;
	vars->map.exit.pos_y = 0;
	vars->qt_moves = 0;
	vars->qt_collected = 0;
	vars->map.width = 0;
	vars->map.height = 0;
	vars->available_collectibles = 0;
	vars->viable_exit = FALSE;
	vars->victory = FALSE;
	vars->end_game = FALSE;
}

void	set_param_game(t_vars*vars, int c, int y, int x)
{
	if (c == START)
	{
		vars->counts.qt_player++;
		vars->player.pos_x = x;
		vars->player.pos_y = y;
	}
	else if (c == EXIT)
	{
		vars->counts.qt_exit++;
		vars->map.exit.pos_x = x;
		vars->map.exit.pos_y = y;
	}
	else if (c == COLLECT)
		vars->counts.qt_collectibles++;
}

int	key_board(int keycode, t_vars*vars)
{
	if (keycode == XK_Escape)
		close_window(vars);
	else if (keycode == XK_w || keycode == XK_Up)
	{
		update_up(vars);
		check_exit(vars);
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		update_right(vars);
		check_exit(vars);
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		update_down(vars);
		check_exit(vars);
	}
	else if (keycode == XK_a || keycode == XK_Left)
	{
		update_left(vars);
		check_exit(vars);
	}
	move_screen_counter(vars);
	return (0);
}
