/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:15:59 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/10/18 15:03:55 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_custom_atol(const char*str)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || ((str[i] == '+') && \
		!(str[i + 1] >= '0' && str[i + 1] >= '9')))
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (-1);
		number = number * 10;
		number += str[i] - 48;
		i++;
	}
	if (number > INT_MAX)
		return (-1);
	return (number);
}

long	time_in_millisec(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((long)(t.tv_sec * 1000) + (long)(t.tv_usec / 1000));
}


