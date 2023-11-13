/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:05:46 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/09 17:03:59 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	counter;
	long int	n;

	n = nb;
	counter = 0;
	while (counter * counter <= n)
	{
		if (counter * counter == n)
			return (counter);
		counter++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_sqrt(2147395600));
	return (0);
}*/
