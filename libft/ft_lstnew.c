/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:51:34 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/29 18:06:32 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void*content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	new_list -> content = content;
	new_list -> next = 0;
	return (new_list);
}

/*#include <stdio.h>

int main()
{
	int value = 42;
	t_list *node = ft_lstnew(&value);
	if (node)
	{
		printf("Node created successfully!\n");
		int *content_ptr = (int *)(node->content);
		printf("Content of the node: %d\n", *content_ptr);

		free(node);
	}
	else
		printf("Failed to create node.\n");
	return (0);
}*/
