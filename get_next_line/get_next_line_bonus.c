/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:22:01 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/19 15:46:29 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "stdio.h"

void	refine_list(t_list**lst)
{
	t_list	*new_node;
	t_list	*last_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (!buffer || !new_node)
		return ;
	last_node = ft_lstlast(*lst);
	i = 0;
	j = 0;
	while (last_node -> content[i] && last_node -> content[i] != '\n')
		++i;
	if (last_node -> content[i] == '\n')
		i += 1;
	while (last_node -> content[i])
	{
		buffer[j++] = last_node->content[i++];
	}
	buffer[j] = '\0';
	new_node -> content = buffer;
	new_node -> next = 0;
	dealloc(lst, new_node, buffer);
}

char	*retrieve_line(t_list*lst)
{
	int		line_len;
	char	*final_line;

	if (!lst)
		return (0);
	line_len = find_length_line(lst);
	final_line = malloc(line_len + 1);
	if (!final_line)
		return (0);
	copy_str(lst, final_line);
	return (final_line);
}

void	append_node(t_list**lst, char*buffer, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	last_node = ft_lstlast(lst[fd]);
	if (!last_node)
		lst[fd] = new_node;
	else
		last_node -> next = new_node;
	new_node -> content = buffer;
	new_node -> next = 0;
}

void	create_list(t_list**lst, int fd)
{
	int		bytes_read;
	char	*buffer;

	while (!find_newline(lst[fd]))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		append_node(lst, buffer, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst[MAX_FD];
	t_list			*temp;
	char			*finished_line;
	int				read_line;

	read_line = read(fd, &finished_line, 0);
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || read_line < 0)
	{
		while (lst[fd])
		{
			temp = lst[fd]->next;
			free(lst[fd]->content);
			free(lst[fd]);
			lst[fd] = temp;
		}
		return (0);
	}
	create_list(lst, fd);
	if (!lst[fd])
		return (0);
	finished_line = retrieve_line(lst[fd]);
	refine_list(&lst[fd]);
	return (finished_line);
}

// int	main()
// {
// 	int	fd;
// 	char	*line;

// 	fd = open("read_error.txt", O_RDONLY);

// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// }
