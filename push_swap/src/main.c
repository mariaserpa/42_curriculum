/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:52:21 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/08 19:33:13 by mrabelo-         ###   ########.fr       */
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
	free_stack(&a);
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

void	append_stack(t_stack**a, int n)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (a == NULL)
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
	}
}
