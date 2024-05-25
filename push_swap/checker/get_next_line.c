/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:29:14 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/25 19:21:42 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	last_node = ft_lst_last(*lst);
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

void	append_node(t_list**lst, char*buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	last_node = ft_lst_last(*lst);
	if (!last_node)
		*lst = new_node;
	else
		last_node -> next = new_node;
	new_node -> content = buffer;
	new_node -> next = 0;
}

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
	t_list			*temp;
	char			*finished_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &finished_line, 0) < 0)
	{
		while (lst)
		{
			temp = lst->next;
			free(lst->content);
			free(lst);
			lst = temp;
		}
		return (0);
	}
	create_list(&lst, fd);
	if (!lst)
		return (0);
	finished_line = retrieve_line(lst);
	refine_list(&lst);
	return (finished_line);
}
