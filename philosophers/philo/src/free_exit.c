/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malu <malu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:54:30 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/10/21 21:02:03 by malu             ###   ########.fr       */
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
		free(data->forks);
	}
	pthread_mutex_destroy(&data->data_lock);
	pthread_mutex_destroy(&data->print_lock);
}
