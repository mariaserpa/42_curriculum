/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:51:50 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/26 11:22:14 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>

void	print_error(char*str);
char	*get_cmd_path(char*cmd, char**envp);
void	free_double_pointer(char**str);
void	execute_command(char*argv, char**envp);
void	child_process(int*fd, char**argv, char**envp);
void	parent_process(int*fd, char**argv, char**envp);

/*bonus files*/
void	here_doc_case(int argc, char**argv, char**envp);
void	get_all_file(int *fd, char *limiter);
void	commands_only_case(int argc, char**argv, char**envp);
void	processing(int argc, char **argv, char **envp, int output);
void	simpler_child_process(int *fd, char*argv, char**envp);

#endif
