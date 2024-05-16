/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:24:07 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/15 18:44:01 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push_cheapest_to_b(t_stack**a, t_stack**b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rr(a, b);
		check_index(*a);
		check_index(*b);
	}
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rrr(a, b);
		check_index(*a);
		check_index(*b);
	}
	prep_push(a, cheapest_node, 'a');
	prep_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void	push_back_to_a(t_stack**a, t_stack**b)
{
	prep_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	prep_push(t_stack**stack, t_stack*top_node, char name_stack)
{
	while (*stack != top_node)
	{
		if (name_stack == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name_stack == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
