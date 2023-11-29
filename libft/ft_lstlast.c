/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:24:51 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/29 19:34:47 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list*lst)
{
	if (!lst)
		return (0);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

/*#include <stdio.h>

int main() {
    // Manually creating a linked list with four nodes

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

    // Node 4
    t_list *fourth = ft_lstnew("Node 4");
    if (!fourth) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(head->content);
        free(head);
        free(second->content);
        free(second);
        free(third->content);
        free(third);
        return 1; // Exit with an error code
    }
    third->next = fourth;
    fourth->next = NULL;

    // Get the last node in the list
    t_list *last_node = ft_lstlast(head);

    // Display the content of the last node
    if (last_node) {
        printf("Content of the last node: %s\n", (char *)last_node->content);
    } else {
        printf("The list is empty.\n");
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
