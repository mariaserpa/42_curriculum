/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:56:54 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/08 17:57:08 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_arg_error(void)
{
	write(1, "Error\n", 6);
	exit (1);
}

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