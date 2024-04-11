/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:13:19 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/07 00:06:57 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	parse_map(t_vars*vars)
{
	int		fd;
	char	*line;

	fd = open(vars->map.map_path, O_RDONLY);
	if (fd < 0)
		treat_read_error(vars, "Map not found");
	line = get_next_line(fd);
	while (line)
	{
		vars->map.display.pos_y++;
		if (vars->map.display.pos_y == 1)
			vars->map.display.pos_x = ft_len_newline(line);
		if (ft_len_newline(line) != vars->map.display.pos_x)
			treat_map_error(vars, "Map is not retangular");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (vars->map.display.pos_y <= 0)
		treat_read_error(vars, "Empty map");
	vars->map.map = ft_calloc(sizeof(char *), (vars->map.display.pos_y + 1));
	if (!vars->map.map)
		exit(1);
	map_store(vars);
}

void	map_store(t_vars*vars)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(vars->map.map_path, O_RDONLY);
	if (fd < 0)
		treat_read_error(vars, "Map not found");
	while (i < vars->map.display.pos_y)
	{
		vars->map.map[i] = get_next_line(fd);
		if (!vars->map.map[i])
		{
			print_error("Empty map");
			exit(1);
		}
		i++;
	}
	vars->map.map[i] = NULL;
	close(fd);
	vars->map.height = vars->map.display.pos_y;
	vars->map.width = vars->map.display.pos_x;
}

void	map_copy(t_vars*vars)
{
	int	y;

	vars->map.map_copy = malloc(sizeof(char *) * (vars->map.height + 1));
	if (!vars->map.map_copy)
		exit(1);
	y = 0;
	while (y < vars->map.height)
	{
		vars->map.map_copy[y] = ft_strdup(vars->map.map[y]);
		y++;
	}
	vars->map.map_copy[y] = NULL;
}

void	validate_map(t_vars*vars)
{
	check_map_components(vars);
	check_wall(vars);
	check_map(vars);
}

void	path_validate(t_vars*vars)
{
	map_copy(vars);
	map_solvable(vars, vars->player);
	final_check(vars);
}
