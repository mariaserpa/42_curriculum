/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:42:37 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/17 00:01:03 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char**argv)
{
	t_stack	*a;
	t_stack	*b;
	bool	flag;
	char	*commands;

	a = NULL;
	flag = false;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		exit (1);
	else if (argc == 2)
	{
		argv = ft_split_mod(argv[1], ' ');
		flag = true;
	}
	start_stack(&a, argv, flag);
	start_second_stack(&b, &a);
	commands = get_next_line(STDIN_FILENO);
	while (commands)
	{
		run_commands(commands, a, b);
		free(commands);
		commands = get_next_line(STDIN_FILENO);
	}
	end_stacks(&a, &b, false);
	return (0);
}

void	run_commands(char*commands, t_stack*a, t_stack*b)
{
	if (!ft_strcmp(commands, "sa\n"))
		sa(&a);
	else if (!ft_strcmp(commands, "sb\n"))
		sb(&b);
	else if (!ft_strcmp(commands, "ss\n"))
		ss(&a, &b);
	else if (!ft_strcmp(commands, "ra\n"))
		ra(&a);
	else if (!ft_strcmp(commands, "rb\n"))
		rb(&b);
	else if (!ft_strcmp(commands, "rr\n"))
		rr(&a, &b);
	else if (!ft_strcmp(commands, "rra\n"))
		rra(&a);
	else if (!ft_strcmp(commands, "rrb\n"))
		rrb(&b);
	else if (!ft_strcmp(commands, "rrr\n"))
		rrr(&a, &b);
	else if (!ft_strcmp(commands, "pa\n"))
		pa(&a, &b);
	else if (!ft_strcmp(commands, "pb\n"))
		pb(&b, &a);
	else
		end_stacks(&a, &b, true);
}

void	end_stacks(t_stack**a, t_stack**b, bool flag)
{
	if (flag == true)
	{
		free_stack(a);
		free_stack(b);
		write(2, "Error\n", 6);
		exit (1);
	}
	else
	{
		free_stack(a);
		free_stack(b);
	}
}

void	start_second_stack(t_stack**b, t_stack**a)
{
	b = malloc(sizeof(t_stack));
	if (!b)
	{
		end_stacks(a, b, true);
	}
	b = NULL;
}

void	check_result(t_stack*a, t_stack*b)
{
	if (check_sort(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
