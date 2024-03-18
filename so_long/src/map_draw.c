/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:25:59 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/02/07 11:53:26 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	render(t_vars*vars)
{
	//draw background
	//draw map
	//draw player
	//draw moves
	//load images
}

void	background_draw(t_vars*vars)
{
	t_pos	grid_pos;

	grid_pos.pos_x = 0;
	grid_pos.pos_y = 0;
	while (grid_pos.pos_y < vars->map.grid_height)
	{
		while (grid_pos.pos_x < vars->map.grid_width)
		{
			mlx_put_image_to_window();
		}
	}
}

void	map_draw(t_vars*vars)
{
}

void	moves_draw(t_vars*vars)
{
}

