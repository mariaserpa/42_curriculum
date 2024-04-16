/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:29:08 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/16 11:22:34 by mrabelo-         ###   ########.fr       */
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
	if (c != 'C' && c != 'P' && c != 'E' && c != '1' && c != '0')
		return (1);
	return (0);
}

int	check_boundaries(t_vars*vars, int pos_y, int pos_x)
{
	if ((vars->map.map[pos_y][pos_x] != '1') && \
		((vars->map.map[pos_y][pos_x] != 'E' && vars->victory == FALSE) || \
		((vars->map.map[pos_y][pos_x] == 'E' || \
		vars->map.map[pos_y][pos_x] != 'E') && vars->victory == TRUE)))
		return (1);
	return (0);
}

void	check_exit(t_vars*vars)
{
	if (vars->qt_collected == vars->counts.qt_collectibles)
	{
		if (vars->map.map[vars->player.pos_y][vars->player.pos_x] == 'E')
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
		(vars->map.map[vars->player.pos_y + 1][vars->player.pos_x] == 'E' || \
		vars->map.map[vars->player.pos_y - 1][vars->player.pos_x] == 'E' || \
		vars->map.map[vars->player.pos_y][vars->player.pos_x + 1] == 'E' || \
		vars->map.map[vars->player.pos_y][vars->player.pos_x - 1] == 'E'))
		ft_printf("There are still some treats left! Go get them!\n");
}

void	check_collectibles(t_vars*vars)
{
	if (vars->qt_collected == vars->counts.qt_collectibles)
		vars->victory = TRUE;
}
