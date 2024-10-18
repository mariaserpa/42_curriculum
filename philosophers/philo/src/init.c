/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:16:40 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/10/17 17:14:33 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_data(t_data *data, char *argv[])
{
	data->num_philo = (int)ft_custom_atol(argv[1]);
	data->time_to_die = (int)ft_custom_atol(argv[2]);
	data->time_to_eat = (int)ft_custom_atol(argv[3]);
	data->time_to_sleep = (int)ft_custom_atol(argv[4]);
	if (argv[5])
		data->num_meals = (int)ft_custom_atol(argv[5]);
	data->start = 0;//check if necessary to initalize with time
	//pthread_mutex_init(&data->data_mutex, NULL);
	//pthread_mutex_init(&data->print_mutex, NULL);
}

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
													* data->num_philo);
	if (!data->forks)
		pe_exit(data, "malloc failed", EXIT_FAILURE);
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			pe_exit(data, "mutex initialization failed", EXIT_FAILURE);
		i++;
	}
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philo)
		pe_exit(data, "malloc failed", EXIT_FAILURE);
	while (i < data->num_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		data->philo[i].qt_meals = 0;
	}
}
