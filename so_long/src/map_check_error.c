/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:34:19 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/06 15:39:10 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	check_map_components(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map.map[y])
	{
		x = 0;
		while (vars->map.map[y][x] != '\0' && vars->map.map[y][x] != '\n')
		{
			if (check_character(vars->map.map[y][x]))
				treat_map_error(vars, "Invalid components");
			else
				set_param_game(vars, vars->map.map[y][x], y, x);
			x++;
		}
		y++;
	}
}

int	check_wall(t_vars *vars)
{
	int		i;

	i = 0;
	while (i < vars->map.height - 1)
	{
		if (vars->map.map[0][i] != WALL ||
			vars->map.map[vars->map.height - 1][i] != WALL ||
			vars->map.map[i][0] != WALL ||
			vars->map.map[i][vars->map.width - 1] != WALL)
		{
			treat_map_error(vars, "Map not surrounded by walls");
		}
		i++;
	}
	return (0);
}

void	check_map(t_vars*vars)
{
	if (vars->counts.qt_player < 1)
		treat_map_error(vars, "Player not found");
	if (vars->counts.qt_player > 1)
		treat_map_error(vars, "Multiple players found");
	if (vars->counts.qt_collectibles < 1)
		treat_map_error(vars, "Any collectibles found");
	if (vars->counts.qt_exit < 1)
		treat_map_error(vars, "Exit not found");
	if (vars->counts.qt_exit > 1)
		treat_map_error(vars, "Multiple exists found");
}

void	final_check(t_vars*vars)
{
	if (vars->viable_exit == FALSE)
		treat_map_error(vars, "Map not solvable");
	if (vars->available_collectibles != vars->counts.qt_collectibles)
		treat_map_error(vars, "Not possible to get all collectibles");
}

void	map_solvable(t_vars*vars, t_pos start_pos)
{
	if (start_pos.pos_y < 0 || start_pos.pos_x < 0 || \
		start_pos.pos_y >= vars->map.height || \
		start_pos.pos_x >= vars->map.width || \
		vars->map.map_copy[start_pos.pos_y][start_pos.pos_x] == WALL || \
		vars->map.map_copy[start_pos.pos_y][start_pos.pos_x] == CHECKED)
		return ;
	if (vars->map.map_copy[start_pos.pos_y][start_pos.pos_x] == EXIT)
		vars->viable_exit = TRUE;
	if (vars->map.map_copy[start_pos.pos_y][start_pos.pos_x] == COLLECT)
		vars->available_collectibles++;
	vars->map.map_copy[start_pos.pos_y][start_pos.pos_x] = CHECKED;
	map_solvable(vars, (t_pos){start_pos.pos_x + 1, start_pos.pos_y});
	map_solvable(vars, (t_pos){start_pos.pos_x - 1, start_pos.pos_y});
	map_solvable(vars, (t_pos){start_pos.pos_x, start_pos.pos_y + 1});
	map_solvable(vars, (t_pos){start_pos.pos_x, start_pos.pos_y - 1});
	return ;
}
