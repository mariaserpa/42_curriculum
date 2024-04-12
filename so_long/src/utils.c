/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:29:08 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/12 17:19:18 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_strcmp(char*s1, char*s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int	ft_len_newline(char*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	print_error(char*str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit (1);
}

void	handle_gnl_error(t_vars*vars, char*line, int fd)
{
	free(line);
	get_next_line(-1);
	close(fd);
	treat_map_error(vars, "Map not retangular");
}
