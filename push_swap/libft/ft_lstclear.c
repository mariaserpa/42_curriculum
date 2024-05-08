/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:19:28 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/04 22:55:09 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_lstclear(t_list**lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	free(*lst);
	*lst = 0;
}

/*#include <stdio.h>

void deleteContent(void *content)
{
	free(content);
}

int	main()
{
	t_list *head = ft_lstnew("Node 1");
	if (!head)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		return (1);
	}
	t_list *second = ft_lstnew("Node 2");
	if (!second)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		ft_lstclear(&head, deleteContent);
		return (1);
	}
	head->next = second;
	t_list *third = ft_lstnew("Node 3");
	if (!third)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		ft_lstclear(&head, deleteContent);
		return (1);
	}
	second->next = third;
	ft_lstclear(&head, deleteContent);
	return (0);
}*/
