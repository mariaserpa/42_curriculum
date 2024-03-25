/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:28:41 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/03/19 14:57:06 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	start_param_game(t_vars*vars, char*map_path)
{
	vars->map.path = map_path;
	vars->qt_collected = 0;
	vars->collectibles = 0;
	vars->qt_moves = 0;
	vars->exit = 0;
	vars->start = 0;
	vars->map.exit = FALSE;
	vars->map.collectibles = 0;
	vars->victory = FALSE;
	vars->end_game = FALSE;
}

void	start_map(t_vars*vars, t_pos*grid_pos)
{
	vars->map.fd = open(vars->map.path, O_RDONLY);
	vars->map.grid = malloc(vars->map.grid_height * sizeof(char *));
	if (vars->map.grid == 0)
	{
		print_error("Unable to allocate memory for grid");
		exit (1);
	}
	vars->map.tile = malloc(vars->map.grid_height * sizeof(t_tile *));
	if (vars->map.tile == 0)
	{
		print_error("Unable to allocate memory for tiles");
		exit (1);
	}
	grid_pos->pos_x = 0;
	grid_pos->pos_y = 0;
}

int	close_window(t_vars*vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit (0);
}

int	key_board(int keycode, t_vars*vars)
{
	if (keycode == 53)
		close_window(vars);
	else if (keycode == 2 && vars->victory == FALSE) //left
		update_position(vars, (t_pos){vars->player.pos.pos_x + 1, \
									vars->player.pos.pos_y});
	else if (keycode == 0 && vars->victory == FALSE) // right
		update_position(vars, (t_pos){vars->player.pos.pos_x - 1, \
									vars->player.pos.pos_y});
	else if (keycode == 13 && vars->victory == FALSE) // up
		update_position(vars, (t_pos){vars->player.pos.pos_x, \
									vars->player.pos.pos_y + 1});
	else if (keycode == 1 && vars->victory == FALSE) // down
		update_position(vars, (t_pos){vars->player.pos.pos_x, \
									vars->player.pos.pos_y - 1});
	return (0);
}

void	update_position(t_vars*vars, t_pos grid_pos)
{
	vars->qt_moves++;
	ft_printf("Total moves: %i\n", vars->qt_moves);
	if (grid_pos.pos_x < vars->map.grid_width && \
		grid_pos.pos_y < vars->map.grid_height)
	{
		if (vars->map.grid[grid_pos.pos_y][grid_pos.pos_x] == COLLECT)
		{
			vars->qt_collected++;
			vars->map.grid[grid_pos.pos_y][grid_pos.pos_x] = FLOOR;
			if (vars->qt_collected == vars->collectibles)
				vars->end_game = TRUE;
			vars->player.pos = grid_pos;
		}
		else if (vars->map.grid[grid_pos.pos_y][grid_pos.pos_x] == EXIT && \
				vars->end_game == TRUE)
		{
			vars->player.pos = grid_pos;
			vars->victory = TRUE;
		}
		else if (vars->map.grid[grid_pos.pos_y][grid_pos.pos_x] != WALL)
			vars->player.pos = grid_pos;
	}
}
