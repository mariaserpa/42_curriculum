/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:50:23 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/29 19:18:57 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list*lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst -> next;
		size++;
	}
	return (size);
}

/*#include <stdio.h>

int main()
{
	t_list *head = ft_lstnew("Node 1");
	ft_lstadd_front(&head, ft_lstnew("Node 2"));
	ft_lstadd_front(&head, ft_lstnew("Node 3"));
	int list_size = ft_lstsize(head);
	printf("Size of the list: %d\n", list_size);
	while (head) {
		t_list *temp = head;
		head = head->next;
		free(temp->content);
		free(temp);
	}
	return (0);
}*/
