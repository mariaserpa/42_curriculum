/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:54:19 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/27 16:39:04 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	processing(int argc, char**argv, char**envp, int output)
{
	int		fd[2];
	int		i;
	pid_t	id_f;

	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		i = 3;
	while (i < argc - 2)
	{
		if (pipe(fd) < 0)
			print_error("Error: Problem ocurred with pipe\n");
		id_f = fork();
		if (id_f < 0)
			print_error("Error: Problem occur while forking\n");
		if (id_f == 0)
			simpler_child_process(fd, argv[i], envp);
		else
			waitpid(id_f, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		close_fd(fd);
		i++;
	}
	dup2(output, STDOUT_FILENO);
	close(output);
	execute_command(argv[argc - 2], envp);
}

void	simpler_child_process(int*fd, char*argv, char**envp)
{
	dup2(fd[1], STDOUT_FILENO);
	close_fd(fd);
	execute_command(argv, envp);
}

void	close_fd(int*fd)
{
	close(fd[0]);
	close(fd[1]);
}
