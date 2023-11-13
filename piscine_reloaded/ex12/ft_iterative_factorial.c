/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:09:52 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/09 15:36:23 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	counter;
	int	number;

	counter = 1;
	number = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		while (counter <= nb)
		{
			number = number * counter;
			counter++;
		}
		return (number);
	}
}
/*#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_iterative_factorial(5));
	return (0);
}*/
