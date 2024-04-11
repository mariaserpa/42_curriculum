/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:29:08 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/07 00:01:56 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_map_name(char*str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 4 && !ft_strcmp(str + len - 4, ".ber"))
		return (0);
	return (1);
}

int	check_character(int c)
{
	if (c != COLLECT && c != START && c != EXIT && c != WALL && c != FLOOR)
		return (1);
	return (0);
}

int	check_boundaries(t_vars*vars, int pos_y, int pos_x)
{
	if ((vars->map.map[pos_y][pos_x] != WALL) && \
		((vars->map.map[pos_y][pos_x] != EXIT && vars->victory == FALSE) || \
		((vars->map.map[pos_y][pos_x] == EXIT || \
		vars->map.map[pos_y][pos_x] != EXIT) && vars->victory == TRUE)))
		return (1);
	return (0);
}

void	check_exit(t_vars*vars)
{
	if (vars->qt_collected == vars->counts.qt_collectibles)
	{
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] == EXIT)
		{
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
					vars->img.exit_open, \
					vars->map.display.pos_x, vars->map.display.pos_y);
			close_window(vars);
		}
		else
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
					vars->img.exit_open, \
					vars->map.exit.pos_x * SIZE, vars->map.exit.pos_y * SIZE);
	}
	else if ((vars->qt_collected != vars->counts.qt_collectibles) && \
		(vars->map.map[vars->player.pos_y + 1][vars->player.pos_x] == EXIT || \
		vars->map.map[vars->player.pos_y - 1][vars->player.pos_x] == EXIT || \
		vars->map.map[vars->player.pos_y][vars->player.pos_x + 1] == EXIT || \
		vars->map.map[vars->player.pos_y][vars->player.pos_x - 1] == EXIT))
	{
		ft_printf("There still some treats left! Go get them!\n");
	}
}

void	check_collectibles(t_vars*vars)
{
	if (vars->qt_collected == vars->counts.qt_collectibles)
		vars->victory = TRUE;
}
