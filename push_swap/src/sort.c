/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:06:48 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/16 15:55:45 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_three(t_stack**a)
{
	int	first_node;
	int	second_node;
	int	third_node;

	first_node = (*a)->value;
	second_node = (*a)->next->value;
	third_node = (*a)->next->next->value;
	if (first_node > second_node && second_node > third_node)
	{
		ra(a);
		sa(a);
	}
	else if (first_node > second_node && first_node > third_node)
		ra(a);
	else if (first_node < second_node && first_node > third_node)
		rra(a);
	else if (first_node > second_node && first_node < third_node)
		sa(a);
	else if (first_node < second_node && first_node < third_node)
	{
		sa(a);
		ra(a);
	}
}

void	big_sort(t_stack**a, t_stack**b)
{
	int	a_len;

	a_len = stack_size(*a);
	if (a_len-- > 3 && !check_sort(*a))
		pb(b, a);
	if (a_len-- > 3 && !check_sort(*a))
		pb(b, a);
	while (a_len-- > 3 && !check_sort(*a))
	{
		prep_stack_a(*a, *b);
		push_cheapest_to_b(a, b);
	}
	// print_stack(*a);
	// printf("\nSTACK B\n");
	// fflush(stdout);
	// print_stack(*b);
	if (!check_sort(*a))
		sort_three(a);
	// print_stack(*a);
	// printf("\nSTACK B\n");
	// fflush(stdout);
	// print_stack(*b);
	while (*b)
	{
		prep_stack_b(*a, *b);
		push_back_to_a(a, b);
	}
	check_index(*a);
	check_top(a);
}
