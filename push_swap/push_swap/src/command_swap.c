/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:22:16 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/10 16:38:11 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	swap(t_stack**start)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (*start == NULL || start == NULL)
		return ;
	first_node = *start;
	second_node = (*start)->next;
	first_node->next = second_node->next;
	second_node->prev = first_node->prev;
	first_node->prev = second_node;
	if (second_node->next)
		second_node->next->prev = first_node;
	second_node->next = first_node;
	*start = second_node;
}

void	sa(t_stack**a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack**b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack**a, t_stack**b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
