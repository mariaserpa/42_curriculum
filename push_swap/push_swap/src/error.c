/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:56:54 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/16 23:26:36 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_error(t_stack**a, char**argv, bool flag)
{
	free_stack(a);
	if (flag)
		free_fake_argv(argv);
	write(1, "Error\n", 6);
	exit (1);
}

int	error_syntax(char*str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
		return (1);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	error_duplicates(t_stack*a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	print_stack(t_stack *a)
{
	printf("Stack contents:\n");
	while (a != NULL)
	{
		printf("Value of the node %d\n", a->value);
		printf("Adress of the node %p\n", a);
		printf("Adress of next node %p\n", a->next);
		printf("Adress of prev node %p\n", a->prev);
		printf("Index of node %d\n", a->index);
		printf("Cost of push for node %d\n", a->push_cost);
		printf("Is above median? %i\n", a->above_median);
		printf("Is it the cheapest? %i\n", a->cheapest);
		a = a->next;
	}
}
