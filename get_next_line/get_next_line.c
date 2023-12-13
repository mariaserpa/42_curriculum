/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:29:14 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/14 00:20:45 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	refine_list(t_list**lst)
{
	t_list	*new_node;
	t_list	*last_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (buffer == 0 || new_node == 0)
		return ;
	last_node = ft_lstlast(*lst);
	i = 0;
	j = 0;
	while (last_node -> content[i] && last_node -> content[i] != '\n')
		++i;
	while (last_node -> content[i] != '\0' && last_node ->content[++i])
		buffer[j++] = last_node->content[i];
	buffer[j] = '\0';
	new_node -> content = buffer;
	new_node -> next = 0;
	dealloc(lst, new_node, buffer);
}

char	*retrive_line(t_list*lst)
{
	int		line_len;
	char	*final_line;

	if (lst == 0)
		return (0);
	line_len = find_length_line(lst);
	final_line = malloc(line_len + 1); //plus 1 bc of the null character
	if (final_line == 0)
		return (0);
	copy_str(lst, final_line);
	return (final_line);
}

void	append_node(t_list**lst, char*buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
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
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		append_node(lst, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*finished_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	create_list(&lst, fd);
	if (!lst)
		return (0);
	finished_line = retrive_line(lst);
	refine_list(&lst);
	return (finished_line);
}

/*#include "stdio.h"
int	main()
{
	int	fd;
	char	*line;
	int	lines;

	lines =1;
	fd = open("text.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
		printf("%d->%s\n", lines++, line);
}*/