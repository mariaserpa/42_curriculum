/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:44:48 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/02 17:37:41 by mrabelo-         ###   ########.fr       */
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

typedef struct sgnl_list
{
	char				*content;
	struct sgnl_list	*next;
}	t_gnlist;

char		*get_next_line(int fd);
char		*retrieve_line(t_gnlist*lst);

int			find_newline(t_gnlist*lst);
int			find_length_line(t_gnlist*lst);

void		refine_list(t_gnlist**lst);
void		copy_str(t_gnlist*lst, char*str);
void		create_list(t_gnlist**lst, int fd);
void		append_node(t_gnlist**lst, char*buffer);
void		dealloc(t_gnlist**lst, t_gnlist*new_node, char*buffer);

t_gnlist	*ft_lstlast(t_gnlist*lst);

#endif
