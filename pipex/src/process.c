/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:12:01 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/26 11:12:02 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	child_process(int*fd, char**argv, char**envp)
{
	int	input;

	input = open(argv[1], O_RDONLY, 0777);
	if (input < 0)
	{
		perror("Input");
		exit (1);
	}
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(input, STDIN_FILENO);
	execute_command(argv[2], envp);
	close(fd[1]);
}

void	parent_process(int*fd, char**argv, char**envp)
{
	int	output;

	output = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (output < 0)
	{
		perror("Output");
		exit (1);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	execute_command(argv[3], envp);
	close(fd[0]);
}
