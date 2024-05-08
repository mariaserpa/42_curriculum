/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:52:21 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/08 17:57:20 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char**argv)
{
	t_stack	*a;
	//t_stack	*b;
	bool	flag;

	a = NULL;
	//b = NULL;
	flag = false;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		print_arg_error();
	else if (argc == 2)
	{
		argv = ft_split_mod(argv[1], ' ');
		flag = true;
	}
	start_stack(&a, argv, flag);
	int i = 0;
	while (argv[i] != NULL) {
		printf("Argument %d: %s\n", i, argv[i]);
		i++;
	}
}

void	start_stack(t_stack**a, char**argv, bool flag)
{
	int		i;
	//long	n;

	i = 1;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			print_error(a, argv, flag);
	//	n = ft_atol(argv[i]);
		i++;
	}
}
