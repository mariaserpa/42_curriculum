/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:24:58 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/16 17:56:53 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	reverse_rotate(t_stack**stack)
{
	t_stack	*last_node;
	t_stack	*last_but_one;

	if (*stack == NULL || stack == NULL)
		return ;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_but_one = last_node->prev;
	last_but_one->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
	*stack = last_node;
}

void	rra(t_stack**a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack**b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack**a, t_stack**b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
