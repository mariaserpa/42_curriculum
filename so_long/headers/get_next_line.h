/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:44:48 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/18 19:39:19 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*retrieve_line(t_list*lst);

int		find_newline(t_list*lst);
int		find_length_line(t_list*lst);

void	refine_list(t_list**lst);
void	copy_str(t_list*lst, char*str);
void	create_list(t_list**lst, int fd);
void	append_node(t_list**lst, char*buffer);
void	dealloc(t_list**lst, t_list*new_node, char*buffer);

t_list	*ft_lstlast(t_list*lst);

#endif
