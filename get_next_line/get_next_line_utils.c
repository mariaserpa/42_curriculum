/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:07:49 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/14 20:09:20 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			++i;
		}
		lst = lst -> next;
	}
	return (0);
}

int	find_length_line(t_list*lst)
{
	int	i;
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		i = 0;
		while (lst -> content[i])
		{
			if (lst -> content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		lst = lst -> next;
	}
	return (len);
}

void	copy_str(t_list*lst, char*str)
{
	int	i;
	int	j;

	if (!lst)
		return ;
	i = 0;
	while (lst)
	{
		j = 0;
		while (lst -> content[j])
		{
			if (lst -> content[j] == '\n')
			{
				str[i] = '\n';
				i++;
				str[i] = '\0';
				return ;
			}
			str[i++] = lst -> content[j++];
		}
		lst = lst -> next;
	}
	str[i] = '\0';
}

void	dealloc(t_list**lst, t_list*new_node, char*buffer)
{
	t_list	*temp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = 0;
	if (new_node -> content[0])
		*lst = new_node;
	else
	{
		free(buffer);
		free(new_node);
	}
}
