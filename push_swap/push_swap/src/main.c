/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:52:21 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/16 20:02:17 by mrabelo-         ###   ########.fr       */
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
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			big_sort(&a, &b);
	}
	free_stack(&a);
}
