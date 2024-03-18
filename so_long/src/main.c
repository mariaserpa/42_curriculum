/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:28:30 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/02/07 11:07:21 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char**argv)
{
	t_vars	vars;

	if (argc == 1)
		print_error("Map not found");
	else if (argc > 2)
		print_error("Too many arguments");
	else if (argc == 2 && check_map_name(argv[1]))
		print_error("Map name is not valid");
	start_param_game(&vars, argv[1]);
	parse_map(&vars.map);
	fill_grid(&vars);
	//free_tiles?
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, vars.map.grid_width, \
								vars.map.grid_height, WINDOW_NAME);
	vars.img = mlx_new_image(vars.mlx, vars.map.grid_width, \
							vars.map.grid_height);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bpp, \
								&vars.line_length, &vars.endian);
	//sprites?
	mlx_key_hook(vars.mlx_win, key_board, &vars);
	mlx_hook(vars.mlx_win, 17, 1L << 0, close_window, &vars);
	mlx_loop_hook();
	mlx_loop(vars.mlx);
}
