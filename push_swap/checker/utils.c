/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:38:28 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/17 11:39:12 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	run_commands(char*commands, t_stack**a, t_stack**b)
{
	if (ft_strncmp(commands, "sa\n", 3) == 0 || \
		ft_strncmp(commands, "sb\n", 3) == 0 || \
		ft_strncmp(commands, "ss\n", 3) == 0)
		check_swap(commands, a, b);
	else if (ft_strncmp(commands, "ra\n", 3) == 0 || \
		ft_strncmp(commands, "rb\n", 3) == 0 || \
		ft_strncmp(commands, "rr\n", 3) == 0)
		check_rotate(commands, a, b);
	else if (ft_strncmp(commands, "rra\n", 4) == 0 || \
		ft_strncmp(commands, "rrb\n", 4) == 0 || \
		ft_strncmp(commands, "rrr\n", 4) == 0)
		check_reverse_rotate(commands, a, b);
	else if (ft_strncmp(commands, "pa\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(commands, "pb\n", 3) == 0)
		push(b, a);
	else
		end_stacks(a, b, true);
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
		exit (0);
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
