/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:52:21 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/16 15:56:05 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char**argv)
{
	t_stack	*a;
	t_stack	*b;
	bool	flag;

	a = NULL;
	b = NULL;
	flag = false;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		exit (1);
	else if (argc == 2)
	{
		argv = ft_split_mod(argv[1], ' ');
		flag = true;
	}
	start_stack(&a, argv, flag);
	if (!check_sort(a))
	{
		//printf("%d\n", stack_size(a));
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			big_sort(&a, &b);
		//print_stack(a);//deletar
	}
	free_stack(&a);
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
