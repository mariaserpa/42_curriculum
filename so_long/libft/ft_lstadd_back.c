/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:36:38 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/04 22:55:09 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_lstadd_back(t_list**lst, t_list*new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
	{
		*lst = new;
		return ;
	}
	last -> next = new;
}

/*#include <stdio.h>

int main() {
    // Manually creating a linked list with three nodes

    // Node 1
    t_list *head = ft_lstnew("Node 1");
    if (!head) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    // Node 2
    t_list *second = ft_lstnew("Node 2");
    if (!second) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(head->content);
        free(head);
        return 1; // Exit with an error code
    }
    head->next = second;

    // Node 3
    t_list *third = ft_lstnew("Node 3");
    if (!third) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(head->content);
        free(head);
        free(second->content);
        free(second);
        return 1; // Exit with an error code
    }
    second->next = third;

    // Adding a new node to the end of the list
    t_list *new_node = ft_lstnew("New Node");
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(head->content);
        free(head);
        free(second->content);
        free(second);
        free(third->content);
        free(third);
        return 1; // Exit with an error code
    }
    ft_lstadd_back(&head, new_node);

    // Display the updated list
    printf("Updated list contents:\n");
    t_list *current = head;
    while (current) {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

    // Clean up - free the memory allocated for the list nodes and their contents
    while (head) {
        t_list *temp = head;
        head = head->next;
        free(temp->content);
        free(temp);
    }

    return 0;
}*/
