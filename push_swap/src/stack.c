/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:57:25 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/16 15:32:42 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	append_stack(t_stack**a, int n)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!a)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = n;
	new_node->next = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = *a;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	start_stack(t_stack**a, char**argv, bool flag)
{
	int		i;
	long	n;

	i = 1;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			print_error(a, argv, flag);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			print_error(a, argv, flag);
		if (error_duplicates(*a, (int)n))
			print_error(a, argv, flag);
		append_stack(a, (int)n);
		i++;
	}
	if (flag)
		free_fake_argv(argv);
}

int	stack_size(t_stack*lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

bool	check_sort(t_stack*a)
{
	if (!a)
		return (true);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

void	check_top(t_stack**a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
