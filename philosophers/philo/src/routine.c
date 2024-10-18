/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:12:57 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/10/18 17:26:34 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start_routine(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].t_lastmeal = data->t_start;
		if (pthread_create(&data->philo[i].td_id, NULL, \
							routine, &data->philo[i]))
			pe_exit(data, "thread init error", EXIT_FAILURE);
		i++;
	}
}
