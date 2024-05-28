/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:06:48 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/28 17:07:36 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "get_next_line.h"
# include "pipex.h"

void	here_doc_case(int argc, char**argv, char**envp);
void	get_all_file(int *fd, char *limiter);
void	commands_only_case(int argc, char**argv, char**envp);
void	processing(int argc, char **argv, char **envp, int output);
void	simpler_child_process(int *fd, char*argv, char**envp);
void	close_fd(int*fd);

#endif
