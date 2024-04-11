/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:25:59 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/09 15:31:30 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	render(t_vars*vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	draw_background(vars, y, x);
	draw_player(vars, y, x);
	draw_collectibles(vars, y, x);
	draw_exit(vars, y, x);
}

void	draw_background(t_vars*vars, int y, int x)
{
	t_pos	pos;

	while (vars->map.map[y])
	{
		pos.pos_y = y * SIZE;
		x = 0;
		while (vars->map.map[y][x] != '\0' && vars->map.map[y][x] != '\n')
		{
			pos.pos_x = x * SIZE;
			if (vars->map.map[y][x] == WALL)
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
								vars->img.wall, pos.pos_x, pos.pos_y);
			}
			else if (vars->map.map[y][x] == FLOOR)
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
							vars->img.background, pos.pos_x, pos.pos_y);
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_vars*vars, int y, int x)
{
	t_pos	pos;

	while (vars->map.map[y])
	{
		pos.pos_y = y * SIZE;
		x = 0;
		while (vars->map.map[y][x] != '\0' && vars->map.map[y][x] != '\n')
		{
			pos.pos_x = x * SIZE;
			if (vars->map.map[y][x] == START)
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
								vars->img.player_down, pos.pos_x, pos.pos_y);
				vars->map.display.pos_x = pos.pos_x;
				vars->map.display.pos_y = pos.pos_y;
			}
			x++;
		}
		y++;
	}
}

void	draw_collectibles(t_vars*vars, int y, int x)
{
	t_pos	pos;

	while (vars->map.map[y])
	{
		pos.pos_y = y * SIZE;
		x = 0;
		while (vars->map.map[y][x] != '\0' && vars->map.map[y][x] != '\n')
		{
			pos.pos_x = x * SIZE;
			if (vars->map.map[y][x] == COLLECT)
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
								vars->img.collectibles, pos.pos_x, pos.pos_y);
			}
			x++;
		}
		y++;
	}
}

void	draw_exit(t_vars*vars, int y, int x)
{
	t_pos	pos;

	while (vars->map.map[y])
	{
		pos.pos_y = y * SIZE;
		x = 0;
		while (vars->map.map[y][x] != '\0' && vars->map.map[y][x] != '\n')
		{
			pos.pos_x = x * SIZE;
			if (vars->map.map[y][x] == EXIT)
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
								vars->img.exit, pos.pos_x, pos.pos_y);
			}
			x++;
		}
		y++;
	}
}
