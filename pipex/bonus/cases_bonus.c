/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:51:38 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/28 17:12:39 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"

void	here_doc_case(int argc, char**argv, char**envp)
{
	int		output;
	int		fd[2];
	pid_t	id_f;

	output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (output < 0)
	{
		perror("Output");
		exit (1);
	}
	if (pipe(fd) < 0)
		print_error("Error: Problem ocurred with pipe\n");
	id_f = fork();
	if (id_f < 0)
		print_error("Error: Problem occur while forking\n");
	if (id_f == 0)
		get_all_file(fd, argv[2]);
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close_fd(fd);
		processing(argc, argv, envp, output);
	}
}

void	get_all_file(int *fd, char *limiter)
{
	char	*line;

	close(fd[0]);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && \
			ft_strlen(line) == ft_strlen(limiter) + 1)
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(fd[1]);
	exit (0); //still needs to be figured it out
}

void	commands_only_case(int argc, char**argv, char**envp)
{
	int	input;
	int	output;

	output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output < 0)
	{
		perror("Output");
		exit (1);
	}
	input = open(argv[1], O_RDONLY, 0777);
	if (input < 0)
	{
		perror("Input");
		exit (1);
	}
	dup2(input, STDIN_FILENO);
	close(input);
	processing(argc, argv, envp, output);
}
