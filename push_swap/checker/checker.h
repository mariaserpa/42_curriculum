/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:34:34 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/17 11:31:28 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap/headers/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*retrieve_line(t_list*lst);
int		find_newline(t_list*lst);
int		find_length_line(t_list*lst);
void	refine_list(t_list**lst);
void	copy_str(t_list*lst, char*str);
void	create_list(t_list**lst, int fd);
void	append_node(t_list**lst, char*buffer);
void	dealloc(t_list**lst, t_list*new_node, char*buffer);

void	start_second_stack(t_stack**b, t_stack**a);
void	end_stacks(t_stack**a, t_stack**b, bool flag);
void	run_commands(char*commands, t_stack**a, t_stack**b);

void	check_swap(char*commands, t_stack**a, t_stack**b);
void	check_rotate(char*commands, t_stack**a, t_stack**b);
void	check_reverse_rotate(char*commands, t_stack**a, t_stack**b);
void	check_result(t_stack*a, t_stack*b);


#endif