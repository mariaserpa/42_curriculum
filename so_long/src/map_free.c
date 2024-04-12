/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:23:16 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/12 15:20:09 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	treat_map_error(t_vars*vars, char*str)
{
	free_double_pointer(vars->map.map);
	free_double_pointer(vars->map.map_copy);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	print_error(str);
}

void	treat_read_error(t_vars*vars, char*str)
{
	mlx_destroy_display(vars->mlx);
	free(vars->map.map);
	free(vars->mlx);
	print_error(str);
}

void	free_double_pointer(char**str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free_pointer(str[i]);
			i++;
		}
		free(str);
		str = NULL;
	}
}

void	free_pointer(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return ;
}

int	close_window(t_vars*vars)
{
	if (vars->victory != TRUE)
		ft_printf("Oh no! Max will be sad without his treats...\n");
	else
		ft_printf("Thank you for helping Max getting his treats!\n");
	mlx_loop_end(vars->mlx);
	mlx_destroy_image(vars->mlx, vars->img.background);
	mlx_destroy_image(vars->mlx, vars->img.collectibles);
	mlx_destroy_image(vars->mlx, vars->img.exit);
	mlx_destroy_image(vars->mlx, vars->img.exit_open);
	mlx_destroy_image(vars->mlx, vars->img.player_left);
	mlx_destroy_image(vars->mlx, vars->img.player_right);
	mlx_destroy_image(vars->mlx, vars->img.player_down);
	mlx_destroy_image(vars->mlx, vars->img.player_up);
	mlx_destroy_image(vars->mlx, vars->img.wall);
	mlx_clear_window(vars->mlx, vars->mlx_win);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_double_pointer(vars->map.map);
	free_double_pointer(vars->map.map_copy);
	exit(0);
}
