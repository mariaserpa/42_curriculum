/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:34:34 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/17 14:28:19 by mrabelo-         ###   ########.fr       */
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

/*utils*/
void	start_second_stack(t_stack**b, t_stack**a);
void	end_stacks(t_stack**a, t_stack**b, bool flag);
void	run_commands(char*commands, t_stack**a, t_stack**b);

/*checks*/
void	check_swap(char*commands, t_stack**a, t_stack**b);
void	check_rotate(char*commands, t_stack**a, t_stack**b);
void	check_reverse_rotate(char*commands, t_stack**a, t_stack**b);
void	check_result(t_stack*a, t_stack*b);

/*get_next_line*/
void	refine_list(t_list**lst);
char	*retrieve_line(t_list*lst);
void	append_node(t_list**lst, char*buffer);
void	create_list(t_list**lst, int fd);
char	*get_next_line(int fd);

/*get_next_line_utils*/
int		find_newline(t_list*lst);
int		find_length_line(t_list*lst);
void	copy_str(t_list*lst, char*str);
void	dealloc(t_list**lst, t_list*new_node, char*buffer);

#endif
