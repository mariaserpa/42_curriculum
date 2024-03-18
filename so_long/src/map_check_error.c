/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:48:42 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/02/06 11:29:17 by mrabelo-         ###   ########.fr       */
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
	if (c != COLLECT || c != START || c != EXIT || c != WALL || c != FLOOR)
		return (1);
	return (0);
}

void	check_param_game(t_vars*vars, char c, t_pos pos)
{
	if (c == START)
	{
		vars->start++;
		vars->player.pos = pos;
		vars->player.start_pos = pos;
	}
	else if (c == EXIT)
		vars->exit++;
	else if (c == COLLECT)
		vars->collectibles++;
}

int	check_wall(t_vars*vars)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < vars->map.grid_width)
	{
		if (vars->map.grid[y][x] != WALL)
			return (1);
		if (vars->map.grid[vars->map.grid_height - 1][x] != WALL)
			return (1);
		x++;
	}
	x = 0;
	while (y < vars->map.grid_height)
	{
		if (vars->map.grid[y][x] != WALL)
			return (1);
		if (vars->map.grid[y][vars->map.grid_width - 1] != WALL)
			return (1);
		y++;
	}
	return (0);
}

void	check_map(t_vars*vars)
{
	if (vars->start < 1)
		print_error("Start position not found");
	if (vars->start > 1)
		print_error("Multiple start positions found");
	if (vars->collectibles < 1)
		print_error("Any collectibles found");
	if (vars->exit < 1)
		print_error("Exit not found");
	if (vars->exit > 1)
		print_error("Multiple exists found");
	if (vars->map.exit == FALSE)
		print_error("Map not solvable");
	if (vars->map.collectibles != vars->collectibles)
		print_error("Not possible to get all collectibles");
}
