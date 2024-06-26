/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:51:15 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/22 15:34:03 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	main(int argc, char**argv, char**envp)
{
	int		fd[2];
	pid_t	id_1;

	if (argc != 5)
		print_error("Error: Invalid number of arguments\n");
	else
	{
		if (pipe(fd) < 0)
			print_error("Error: Problem ocurred with pipe\n");
		id_1 = fork();
		if (id_1 < 0)
			print_error("Error: Problem occur while forking\n");
		if (id_1 == 0)
			child_process(fd, argv, envp);
		else
		{
			waitpid(id_1, NULL, 0);
			parent_process(fd, argv, envp);
		}
	}
	return (0);
}
