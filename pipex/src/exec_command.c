/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:11:31 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/27 10:28:41 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

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
		perror("Command");
		exit (127);
	}
	if (execve(cmd_path, cmd, envp) < 0)
		print_error("Error: Not possible to execute command\n");
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
		if (access(result, F_OK | X_OK) == 0)
			return (result);
		free(result);
		i++;
	}
	free_double_pointer(paths);
	return (NULL);
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

void	print_error(char*str)
{
	write(1, str, ft_strlen(str));
	exit (127);
}
