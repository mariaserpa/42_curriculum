/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:29:14 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/12 20:47:27 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* put it on utils*/

t_list	*ft_lstlast(t_list*lst)
{
	if (!lst)
		return (0);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

int	find_newline(t_list*lst)
{
	int	i;

	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst -> content[i] && i < BUFFER_SIZE)
		{
			if (lst -> content[i] == '\n')
				return (1);
			i++;
		}
		lst = lst -> next;
	}
	return (0);
}

char	*retrive_line()
{

}

void	append_list(t_list**lst, char*buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	last_node = ft_lstlast(*lst);
	if (!last_node)
		*lst = new_node;
	else
		last_node -> next = new_node;
	new_node -> content = buffer;
	new_node -> next = 0;
}



/*why it needs to be a pointer to a pointer?
why it needs to use find_newline?*/
void	create_list(t_list**lst, int fd)
{
	int		bytes_read;
	char	*buffer;

	while (!find_newline(*lst))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		ft_append_list(lst, buffer);
	}
}






char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	create_list(&lst, fd);
	if (!lst)
		return (0);
	next_line =

}
