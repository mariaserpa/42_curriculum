/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:25:59 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/03/20 15:56:09 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	render(t_vars*vars)
{
	background_draw(vars);
	if (!vars->victory)
	{
		map_draw(vars);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->sprite_player.sprite_img, vars->player.pos.pos_x * SIZE, \
				vars->player.pos.pos_y * SIZE);
		moves_display(vars);
	}
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->sprite_win.sprite_img, 0, 0);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->qt_display[vars->qt_moves / 100].sprite_img, \
				1 * SIZE + 10, 3 * SIZE +10);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->qt_display[(vars->qt_moves / 10) % 10].sprite_img, \
				2 * SIZE + 10, 3 * SIZE +10);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->qt_display[(vars->qt_moves % 100) % 10].sprite_img, \
				3 * SIZE + 10, 3 * SIZE +10);
	}
	return (0);
}

void	background_draw(t_vars*vars)
{
	t_pos	grid_pos;

	grid_pos.pos_x = 0;
	grid_pos.pos_y = 0;
	while (grid_pos.pos_y < vars->map.grid_height * SIZE)
	{
		while (grid_pos.pos_x < vars->map.grid_width * SIZE)
		{
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
					vars->sprite_background.sprite_img, grid_pos.pos_x, \
					grid_pos.pos_y);
			grid_pos.pos_x += SIZE;
		}
		grid_pos.pos_x = 0;
		grid_pos.pos_y += SIZE;
	}
}

void	map_draw(t_vars*vars)
{
	t_pos	g_pos;
	int		g_value;

	g_pos.pos_x = 0;
	g_pos.pos_y = 0;
	while (g_pos.pos_y < vars->map.grid_height * SIZE)
	{
		while (g_pos.pos_x < vars->map.grid_width * SIZE)
		{
			g_value = vars->map.grid[g_pos.pos_y / SIZE][g_pos.pos_x / SIZE];
			if (g_value == WALL)
				map_sprite_to_window(vars, g_pos, WALL);
			else if (g_value == FLOOR)
				map_sprite_to_window(vars, g_pos, FLOOR);
			else if (g_value == START)
				map_sprite_to_window(vars, g_pos, START);
			else if (g_value == COLLECT)
				map_sprite_to_window(vars, g_pos, COLLECT);
			else if (g_value == EXIT)
				map_sprite_to_window(vars, g_pos, EXIT);
			g_pos.pos_x += SIZE;
		}
		g_pos.pos_x = 0;
		g_pos.pos_y += SIZE;
	}
}

void	moves_display(t_vars*vars)
{
	int	h;
	int	t;
	int	u;

	h = vars->qt_moves / 100;
	t = (vars->qt_moves / 10) % 10;
	u = (vars->qt_moves % 100) % 10;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
			vars->qt_display[h].sprite_img, 0 * SIZE + 10, 10);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
			vars->qt_display[t].sprite_img, 1 * SIZE + 10, 10);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
			vars->qt_display[u].sprite_img, 2 * SIZE + 10, 10);
}

void	map_sprite_to_window(t_vars*vars, t_pos g_pos, char g_value)
{
	if (g_value == WALL)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->sprite_wall.sprite_img, g_pos.pos_x, g_pos.pos_y);
	else if (g_value == FLOOR)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->sprite_background.sprite_img, g_pos.pos_x, g_pos.pos_y);
	else if (g_value == START)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->sprite_start.sprite_img, g_pos.pos_x, g_pos.pos_y);
	else if (g_value == COLLECT)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->sprite_collectible.sprite_img, g_pos.pos_x, g_pos.pos_y);
	else if (g_value == EXIT)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->sprite_exit.sprite_img, g_pos.pos_x, g_pos.pos_y);
}
