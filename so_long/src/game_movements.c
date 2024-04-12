/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:20:21 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/12 15:57:29 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	first_update(t_vars*vars)
{
	if (vars->map.map[vars->player.pos_y][vars->player.pos_x] != 'E')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.background, \
							vars->map.display.pos_x, vars->map.display.pos_y);
	else
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.exit, \
							vars->map.display.pos_x, vars->map.display.pos_y);
}

void	update_up(t_vars*vars)
{
	if (check_boundaries(vars, vars->player.pos_y - 1, vars->player.pos_x))
	{
		first_update(vars);
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] != 'E')
			vars->map.map[vars->player.pos_y][vars->player.pos_x] = '0';
		vars->map.display.pos_y -= SIZE;
		vars->player.pos_y -= 1;
		vars->qt_moves++;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.player_up, \
						vars->map.display.pos_x, vars->map.display.pos_y);
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] == '0')
			vars->map.map[vars->player.pos_y][vars->player.pos_x] = 'P';
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] == 'C')
		{
			vars->map.map[vars->player.pos_y][vars->player.pos_x] = '0';
			vars->qt_collected++;
		}
		ft_printf("Total moves: %d\n", vars->qt_moves);
	}
	check_collectibles(vars);
}

void	update_down(t_vars*vars)
{
	if (check_boundaries(vars, vars->player.pos_y + 1, vars->player.pos_x))
	{
		first_update(vars);
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] != 'E')
			vars->map.map[vars->player.pos_y][vars->player.pos_x] = '0';
		vars->map.display.pos_y += SIZE;
		vars->player.pos_y += 1;
		vars->qt_moves++;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
						vars->img.player_down, \
						vars->map.display.pos_x, vars->map.display.pos_y);
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] == '0')
			vars->map.map[vars->player.pos_y][vars->player.pos_x] = 'P';
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] == 'C')
		{
			vars->map.map[vars->player.pos_y][vars->player.pos_x] = '0';
			vars->qt_collected++;
		}
		ft_printf("Total moves: %d\n", vars->qt_moves);
	}
	check_collectibles(vars);
}

void	update_left(t_vars*vars)
{
	if (check_boundaries(vars, vars->player.pos_y, vars->player.pos_x - 1))
	{
		first_update(vars);
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] != 'E')
			vars->map.map[vars->player.pos_y][vars->player.pos_x] = '0';
		vars->map.display.pos_x -= SIZE;
		vars->player.pos_x -= 1;
		vars->qt_moves++;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
						vars->img.player_left, \
						vars->map.display.pos_x, vars->map.display.pos_y);
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] == '0')
			vars->map.map[vars->player.pos_y][vars->player.pos_x] = 'P';
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] == 'C')
		{
			vars->map.map[vars->player.pos_y][vars->player.pos_x] = '0';
			vars->qt_collected++;
		}
		ft_printf("Total moves: %d\n", vars->qt_moves);
	}
	check_collectibles(vars);
}

void	update_right(t_vars*vars)
{
	if (check_boundaries(vars, vars->player.pos_y, vars->player.pos_x + 1))
	{
		first_update(vars);
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] != 'E')
			vars->map.map[vars->player.pos_y][vars->player.pos_x] = '0';
		vars->map.display.pos_x += SIZE;
		vars->player.pos_x += 1;
		vars->qt_moves++;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
						vars->img.player_right, \
						vars->map.display.pos_x, vars->map.display.pos_y);
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] == '0')
			vars->map.map[vars->player.pos_y][vars->player.pos_x] = 'P';
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] == 'C')
		{
			vars->map.map[vars->player.pos_y][vars->player.pos_x] = '0';
			vars->qt_collected++;
		}
		ft_printf("Total moves: %d\n", vars->qt_moves);
	}
	check_collectibles(vars);
}
