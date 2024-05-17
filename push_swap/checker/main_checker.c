/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:42:37 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/17 11:39:19 by mrabelo-         ###   ########.fr       */
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
		run_commands(commands, &a, &b);
		free(commands);
		commands = get_next_line(STDIN_FILENO);
	}
	check_result(a, b);
	end_stacks(&a, &b, false);
}
