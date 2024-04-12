/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:37:15 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/12 17:12:58 by mrabelo-         ###   ########.fr       */
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
	if (vars->img.background == NULL || vars->img.wall == NULL || \
		vars->img.player_down == NULL || vars->img.player_up == NULL || \
		vars->img.player_left == NULL || vars->img.player_right == NULL || \
		vars->img.exit == NULL || vars->img.collectibles == NULL || \
		vars->img.exit_open == NULL)
	{
		free(vars->img.background);
		free(vars->img.wall);
		free(vars->img.player_up);
		free(vars->img.player_down);
		free(vars->img.player_left);
		free(vars->img.player_right);
		free(vars->img.collectibles);
		free(vars->img.exit);
		free(vars->img.exit_open);
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
