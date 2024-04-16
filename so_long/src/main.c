/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:28:30 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/16 13:39:53 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char**argv)
{
	t_vars	vars;

	if (argc != 2)
		print_error("Number of arguments invalid");
	else if (argc == 2 && check_map_name(argv[1]))
		print_error("Map name is not valid");
	start_param_game(&vars, argv[1]);
	vars.mlx = mlx_init();
	parse_map(&vars);
	validate_map(&vars);
	path_validate(&vars);
	load_xpm(&vars);
	ft_printf("Hey @you, could you make Max happy and get all of his treats?\n");
	vars.mlx_win = mlx_new_window(vars.mlx, vars.map.width * SIZE, \
								vars.map.height * SIZE, WINDOW_NAME);
	render(&vars);
	mlx_key_hook(vars.mlx_win, key_board, &vars);
	mlx_hook(vars.mlx_win, 17, 1L << 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
