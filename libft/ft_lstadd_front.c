/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:27:53 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/29 18:46:41 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list**lst, t_list*new)
{
	new -> next = *lst;
	*lst = new;
}

/*#include <stdio.h>

int main()
{
	t_list *head = NULL;
	t_list *newNode = (t_list *)malloc(sizeof(t_list));
	newNode->content = "New Node";
	newNode->next = NULL;
	ft_lstadd_front(&head, newNode);
	if (head != NULL) {
		printf("New node added successfully to the front of the list.\n");
		printf("Content of the first node: %s\n", (char *)head->content);
	}
	else
		printf("Failed to add a new node.\n");
	return (0);
}*/
