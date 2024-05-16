/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:25:10 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/16 17:57:08 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	rotate(t_stack**stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (*stack == NULL || stack == NULL)
		return ;
	first_node = *stack;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = first_node;
	*stack = first_node->next;
	(*stack)->prev = NULL;
	first_node->prev = last_node;
	first_node->next = NULL;
}

void	ra(t_stack**a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack**b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack**a, t_stack**b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
