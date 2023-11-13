/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:45:38 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/06 17:55:00 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int*a, int*b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*#include <stdio.h>

int	main(void)
{
	int n_a = 1;
	int n_b = 2;

	printf("before: %d\n", n_b);
	ft_swap(&n_a, &n_b);
	printf("after: %d\n", n_b);
}*/
