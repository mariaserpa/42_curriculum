/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:37:15 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/16 14:27:45 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	load_xpm(t_vars*vars)
{
	int	x;
	int	y;

	x = vars->map.width * SIZE;
	y = vars->map.height * SIZE;
	load_img(vars, x, y);
	img_control(vars);
}

void	load_img(t_vars*vars, int x, int y)
{
	vars->img.background = mlx_xpm_file_to_image(vars->mlx,
			"./images/sprite_background.xpm", &x, &y);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx,
			"./images/sprite_wall.xpm", &x, &y);
	vars->img.player_up = mlx_xpm_file_to_image(vars->mlx,
			"./images/sprite_player_up.xpm", &x, &y);
	vars->img.player_down = mlx_xpm_file_to_image(vars->mlx,
			"./images/sprite_player_down.xpm", &x, &y);
	vars->img.player_right = mlx_xpm_file_to_image(vars->mlx,
			"./images/sprite_player_right.xpm", &x, &y);
	vars->img.player_left = mlx_xpm_file_to_image(vars->mlx,
			"./images/sprite_player_left.xpm", &x, &y);
	vars->img.collectibles = mlx_xpm_file_to_image(vars->mlx,
			"./images/sprite_collectibles.xpm", &x, &y);
	vars->img.exit = mlx_xpm_file_to_image(vars->mlx,
			"./images/sprite_exit.xpm", &x, &y);
	vars->img.exit_open = mlx_xpm_file_to_image(vars->mlx,
			"./images/sprite_exit_open.xpm", &x, &y);
}

void	img_control(t_vars*vars)
{
	if (!vars->img.background || !vars->img.exit_open || !vars->img.player_down \
		|| !vars->img.player_up || !vars->img.player_left || !vars->img.exit || \
		!vars->img.player_right || !vars->img.collectibles || !vars->img.wall)
	{
		destroy_images(vars);
		vars->img.wall = NULL;
		vars->img.background = NULL;
		vars->img.player_up = NULL;
		vars->img.player_down = NULL;
		vars->img.player_left = NULL;
		vars->img.player_right = NULL;
		vars->img.collectibles = NULL;
		vars->img.exit = NULL;
		vars->img.exit_open = NULL;
		treat_map_error(vars, "Invalid image");
	}
}

int	move_screen_counter(t_vars*vars)
{
	char	*count_string;
	char	*print_string;

	draw_background(vars, vars->map.height - 1, 00);
	count_string = ft_itoa(vars->qt_moves);
	print_string = ft_strjoin("moves: ", count_string);
	mlx_string_put(vars->mlx, vars->mlx_win, 24,
		vars->map.height * SIZE - 10, 0xFFFFFF, print_string);
	free_pointer(count_string);
	free_pointer(print_string);
	return (0);
}

void	destroy_images(t_vars*vars)
{
	if (vars->img.background)
		mlx_destroy_image(vars->mlx, vars->img.background);
	if (vars->img.collectibles)
		mlx_destroy_image(vars->mlx, vars->img.collectibles);
	if (vars->img.exit)
		mlx_destroy_image(vars->mlx, vars->img.exit);
	if (vars->img.exit_open)
		mlx_destroy_image(vars->mlx, vars->img.exit_open);
	if (vars->img.player_left)
		mlx_destroy_image(vars->mlx, vars->img.player_left);
	if (vars->img.player_right)
		mlx_destroy_image(vars->mlx, vars->img.player_right);
	if (vars->img.player_down)
		mlx_destroy_image(vars->mlx, vars->img.player_down);
	if (vars->img.player_up)
		mlx_destroy_image(vars->mlx, vars->img.player_up);
	if (vars->img.wall)
		mlx_destroy_image(vars->mlx, vars->img.wall);
}
