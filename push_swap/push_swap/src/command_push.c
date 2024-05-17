/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:24:43 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/17 11:34:23 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push(t_stack**dest, t_stack**src)
{
	t_stack	*first_node;

	if (*src == NULL)
		return ;
	first_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	first_node->prev = NULL;
	if (*dest == NULL)
	{
		first_node->next = NULL;
		*dest = first_node;
	}
	else
	{
		first_node->next = *dest;
		(*dest)->prev = first_node;
		*dest = first_node;
	}
}

void	pa(t_stack**a, t_stack**b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack**b, t_stack**a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
