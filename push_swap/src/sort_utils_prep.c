/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_prep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:49:53 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/15 18:51:41 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	find_target_a(t_stack*a, t_stack*b)
{
	t_stack	*current_node;
	int		best_match;//suppose to be long?

	while (a)
	{
		best_match = INT_MIN;
		current_node = b;
		while (current_node)
		{
			if (current_node->value < a->value
				&& current_node->value >= best_match)
			{
				best_match = current_node->value;
				a->target_node = current_node;//different
			}
			current_node = current_node->next;
		}
		if (best_match == INT_MIN)
			a->target_node = find_max(b);
		a = a->next;
	}
}

static void	cost_analysis(t_stack*a, t_stack*b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_median)
			a->push_cost = len_a - a->index;
		if (a->above_median && a->target_node->above_median
			&& a->index < a->target_node->index)
			a->push_cost = a->target_node->index;
		else if (!a->above_median && !a->target_node->above_median
			&& (len_b - a->target_node->index) > (len_a - a->index))
			a->push_cost = (len_b - a->target_node->index);
		else if (a->above_median && !a->target_node->above_median)
			a->push_cost += (len_b - a->target_node->index);
		else if (!a->above_median && a->target_node->above_median)
			a->push_cost += a->target_node->index;
		a = a->next;
	}
}

void	prep_stack_a(t_stack*a, t_stack*b)
{
	check_index(a);
	check_index(b);
	find_target_a(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}

static void	find_target_b(t_stack*a, t_stack*b)
{
	t_stack	*current_node;
	int		best_match;

	while (b)
	{
		best_match = INT_MAX;
		current_node = a;
		while (current_node)
		{
			if (current_node->value > b->value
				&& current_node->value < best_match)
			{
				best_match = current_node->value;
				b->target_node = current_node;
			}
			current_node = current_node->next;
		}
		if (best_match == INT_MAX)
			b->target_node = find_min(a);
		b = b->next;
	}
}

void	prep_stack_b(t_stack*a, t_stack*b)
{
	check_index(a);
	check_index(b);
	find_target_b(a, b);
}
