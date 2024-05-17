/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:29:32 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/17 11:36:12 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_swap(char*commands, t_stack**a, t_stack**b)
{
	if (commands[1] == 'a')
		swap(a);
	else if (commands[1] == 'b')
		swap(b);
	else if (commands[1] == 's')
	{
		swap(a);
		swap(b);
	}
}

void	check_rotate(char*commands, t_stack**a, t_stack**b)
{
	if (commands[1] == 'a')
		rotate(a);
	else if (commands[1] == 'b')
		rotate(b);
	else if (commands[1] == 'r')
	{
		rotate(a);
		rotate(b);
	}
}

void	check_reverse_rotate(char*commands, t_stack**a, t_stack**b)
{
	if (commands[2] == 'a')
		reverse_rotate(a);
	else if (commands[2] == 'b')
		reverse_rotate(b);
	else if (commands[2] == 'r')
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void	check_result(t_stack*a, t_stack*b)
{
	if (check_sort(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
