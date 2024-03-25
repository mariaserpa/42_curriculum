/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:37:15 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/03/21 06:29:07 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	load_sprites(t_vars*vars)
{
	vars->sprite_wall.sprite_img = mlx_xpm_file_to_image(vars->mlx, \
			"images/sprite_wall.xpm", &vars->sprite_wall.pos_w, \
			&vars->sprite_wall.pos_h);
	vars->sprite_background.sprite_img = mlx_xpm_file_to_image(vars->mlx, \
			"images/background.xpm", &vars->sprite_background.pos_w, \
			&vars->sprite_background.pos_h);
	vars->sprite_start.sprite_img = mlx_xpm_file_to_image(vars->mlx, \
			"images/sprite_start.xpm", &vars->sprite_start.pos_w, \
			&vars->sprite_start.pos_h);
	vars->sprite_player.sprite_img = mlx_xpm_file_to_image(vars->mlx, \
			"images/sprite_player_corgi.xpm", &vars->sprite_player.pos_w, \
			&vars->sprite_player.pos_h);
	vars->sprite_collectible.sprite_img = mlx_xpm_file_to_image(vars->mlx, \
			"images/sprite_collectibles.xpm", &vars->sprite_collectible.pos_w, \
			&vars->sprite_collectible.pos_h);
	vars->sprite_exit.sprite_img = mlx_xpm_file_to_image(vars->mlx, \
			"images/sprite_exit.xpm", &vars->sprite_exit.pos_w, \
			&vars->sprite_exit.pos_h);
	vars->sprite_win.sprite_img = mlx_xpm_file_to_image(vars->mlx, \
			"images/sprite_victory.xpm", &vars->sprite_win.pos_w, \
			&vars->sprite_win.pos_h);
	load_qt_move_display(vars);
}

void	load_qt_move_display(t_vars*vars)
{
	int		i;
	char	*file_paths[10];

	i = 0;
	file_paths[0] = "images/sprite_0.xpm";
	file_paths[1] = "images/sprite_1.xpm";
	file_paths[2] = "images/sprite_2.xpm";
	file_paths[3] = "images/sprite_3.xpm";
	file_paths[4] = "images/sprite_4.xpm";
	file_paths[5] = "images/sprite_5.xpm";
	file_paths[6] = "images/sprite_6.xpm";
	file_paths[7] = "images/sprite_7.xpm";
	file_paths[8] = "images/sprite_8.xpm";
	file_paths[9] = "images/sprite_9.xpm";
	vars->qt_display = malloc(10 * sizeof(t_sprite));
	if (vars->qt_display == 0)
		return ;
	while (i < 10)
	{
		vars->qt_display[i].sprite_img = mlx_xpm_file_to_image(vars->mlx, \
			file_paths[i], &vars->qt_display[i].pos_w, \
			&vars->qt_display[i].pos_h);
		i++;
	}
}
