/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:25:16 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/04 22:55:09 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_atoi(const char*str)
{
	int	i;
	int	signal;
	int	number;

	i = 0;
	signal = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		number = number * 10;
		number += str[i] - 48;
		i++;
	}
	return (signal * number);
}
/*#include <stdio.h>

int	main(void)
{
	char s[] = "    -1234ab567";

	printf("%d\n", ft_atoi(s));
}*/
