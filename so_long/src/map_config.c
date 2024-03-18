/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:13:19 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/02/06 11:29:52 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	parse_map(t_map*map)
{
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		print_error("Map not found");
	map->grid_height = 0;
	map->grid_width = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->grid_height++;
		if (map->grid_height == 1)
			map->grid_width = ft_newline_len(line);
		if (ft_newline_len(line) != map->grid_width)
			print_error("Map is not retangular");
		line = get_next_line(fd);
	}
	close(fd);
	if (map->grid_height == 0)
		print_error("Empty map");
	return (1);
}

void	malloc_line(t_vars*vars, t_pos grid_pos)
{
	vars->map.grid[grid_pos.pos_y] = malloc((vars->map.grid_width - 1) \
														* sizeof(char));
	if (vars->map.grid[grid_pos.pos_y] == 0)
	{
		print_error("Unable to allocate memory to fill grid");
		exit (1);
	}
	vars->map.tile[grid_pos.pos_y] = malloc((vars->map.grid_width - 1) \
														* sizeof(char));
	if (vars->map.tile[grid_pos.pos_y] == 0)
	{
		print_error("Unable to allocate memory to fill tiles");
		exit (1);
	}
}

void	fill_tile(t_vars*vars, char*line, t_pos grid_pos)
{
	vars->map.grid[grid_pos.pos_y][grid_pos.pos_x] = line[grid_pos.pos_x];
	vars->map.tile[grid_pos.pos_y][grid_pos.pos_x].type = line[grid_pos.pos_x];
	vars->map.tile[grid_pos.pos_y][grid_pos.pos_x].check = 0;
	if (check_character(vars->map.tile[grid_pos.pos_y][grid_pos.pos_x].type))
		print_error("Wrong character inserted in the map file");
}

void	map_solvable(t_vars*vars, t_pos grid_pos)
{
	if (vars->map.grid[grid_pos.pos_y][grid_pos.pos_x] == WALL || \
		vars->map.tile[grid_pos.pos_y][grid_pos.pos_x].check == 1 || \
		grid_pos.pos_y < 0 || grid_pos.pos_x < 0 || \
		grid_pos.pos_y > vars->map.grid_height || \
		grid_pos.pos_x > vars->map.grid_width)
		return ;
	vars->map.tile[grid_pos.pos_y][grid_pos.pos_x].check = 1;
	if (vars->map.grid[grid_pos.pos_y][grid_pos.pos_x] == EXIT)
		vars->map.exit = TRUE;
	if (vars->map.grid[grid_pos.pos_y][grid_pos.pos_x] == COLLECT)
		vars->map.collectibles++;
	map_solvable(vars, (t_pos){grid_pos.pos_x + 1, grid_pos.pos_y});
	map_solvable(vars, (t_pos){grid_pos.pos_x - 1, grid_pos.pos_y});
	map_solvable(vars, (t_pos){grid_pos.pos_x, grid_pos.pos_y + 1});
	map_solvable(vars, (t_pos){grid_pos.pos_x, grid_pos.pos_y - 1});
	return ;
}

int	fill_grid(t_vars*vars)
{
	t_pos	grid_pos;
	char	*line;

	start_map(vars, &grid_pos);
	line = get_next_line(vars->map.fd);
	while (line)
	{
		malloc_line(vars, grid_pos);
		while (grid_pos.pos_x < vars->map.grid_width)
		{
			fill_tile(vars, line, grid_pos);
			check_param_game(vars, \
				vars->map.grid[grid_pos.pos_x][grid_pos.pos_y], grid_pos);
			grid_pos.pos_x++;
		}
		grid_pos.pos_x = 0;
		grid_pos.pos_y++;
		line = get_next_line(vars->map.fd);
	}
	close(vars->map.fd);
	if (check_wall(vars))
		print_error("Map not surrounded by walls");
	map_solvable(vars, vars->player.pos);
	check_map(vars);
	return (1);
}
