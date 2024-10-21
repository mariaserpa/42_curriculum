/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:54:30 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/10/20 17:10:58 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	pe_exit(t_data *data, char *msg, int code)
{
	if (data)
		free_structure(data);
	if (msg)
		printf("%s\n", msg);
	exit(code);
}

void	free_structure(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		while (i < data->num_philo)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
	}
	//if (data->philo)
	//	free(data->philo);
	pthread_mutex_destroy(&data->data_lock);
	pthread_mutex_destroy(&data->print_lock);
	//free(data);
}

