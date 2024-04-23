/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:51:15 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/22 22:50:23 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	main(int argc, char**argv, char**envp)
{
	int		input;
	int		output;
	int		fd[2];
	pid_t	id_1;

	if (argc != 5)
		print_error("Invalid number of arguments\n");
	open_files(argc, argv, &input, &output);
	if (pipe(fd) < 0)
		print_error("Problem ocurred with pipe");
	id_1 = fork();
	if (id_1 < 0)
		print_error("Problem occur while forking");
	if (id_1 == 0)
		child_process(fd, argv, envp, input);
	else
	{
		waitpid(id_1, NULL, 0);
		parent_process(fd, argv, envp, output);
	}
	return (0);
}

void	open_files(int argc, char**argv, int *input, int *output)
{
	*input = open(argv[1], O_RDONLY);
	if (*input < 0)
	{
		print_error("Error opening input file");
		exit (1);
	}
	*output = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644); //file permission param 0644 -> Read and write permissions for the owner, and read-only permissions for group and others.
	if (*output < 0)
	{
		print_error("Error opening output file");
		exit (1);
	}
}

char	*get_cmd_path(char*cmd, char**envp)
{
	char	**paths;
	char	*temp;
	char	*result;
	int		i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		result = ft_strjoin(temp, cmd);
		free(temp);
		if (access(result, F_OK) == 0)
			return (result);
		free(result);
		i++;
	}
	free_double_pointer(paths);
	return (0);
}

void	free_double_pointer(char**str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	child_process(int*fd, char**argv, char**envp, int input)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(input, STDIN_FILENO);
	execute_command(argv[2], envp);
	close(fd[1]);
}

void	parent_process(int*fd, char**argv, char**envp, int output)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	execute_command(argv[3], envp);
	close(fd[0]);
}

void	execute_command(char*argv, char**envp)
{
	char	**cmd;
	int		i;
	char	*cmd_path;

	i = 0;
	cmd = ft_split(argv, ' ');
	cmd_path = get_cmd_path(cmd[0], envp);
	if (!cmd_path)
	{
		while (cmd[i])
		{
			free(cmd[i]);
			i++;
		}
		free(cmd);
		print_error("Error finding cmd path");
	}
	if (execve(cmd_path, cmd, envp) < 0)
		print_error("Error executing command");
}

void	print_error(char*str)
{
	write(1, str, ft_strlen(str));
	exit (1);
}
