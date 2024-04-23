/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:51:15 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/23 17:51:34 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	main(int argc, char**argv, char**envp)
{
	int		fd[2];
	pid_t	id_1;

	if (argc != 5)
		print_error("Invalid number of arguments\n");
	if (pipe(fd) < 0)
		print_error("Problem ocurred with pipe\n");
	id_1 = fork();
	if (id_1 < 0)
		print_error("Problem occur while forking\n");
	if (id_1 == 0)
		child_process(fd, argv, envp);
	else
	{
		waitpid(id_1, NULL, 0);
		parent_process(fd, argv, envp);
	}
	return (0);
}
