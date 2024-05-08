/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:56:13 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/08 17:56:28 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	free_fake_argv(char**argv)
{
	int	i;

	i = 0;
	if (argv == NULL || argv[0] == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv); //check
}

void	free_stack(t_stack**stack)
{
	if (*stack == NULL)
		return;
	free_stack(&((*stack)->next));
	free(*stack);
	*stack = NULL;
}