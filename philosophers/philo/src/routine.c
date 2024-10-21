/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malu <malu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:12:57 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/10/22 00:52:26 by malu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	check_one_philo_case(philo);
	while (1)
	{
		pthread_mutex_lock(&philo->data->data_lock);
		if (philo->data->l_status == DEAD || philo->data->l_status == STOP)
		{
			pthread_mutex_unlock(&philo->data->data_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->data_lock);
		prepare_to_eat(philo);
		eat(philo);
		sleep_think(philo);
	}
	return (NULL);
}

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

static int	check_status(t_data *data)
{
	int		i;
	long	curr_time;

	i = 0;
	while (i < data->num_philo)
	{
		curr_time = time_in_millisec();
		pthread_mutex_lock(&data->data_lock);
		if (curr_time - data->philo[i].t_lastmeal > data->time_to_die)
		{
			print_status(&data->philo[i], "died");
			data->l_status = DEAD;
			pthread_mutex_unlock(&data->data_lock);
			return (1);
		}
		i++;
		pthread_mutex_unlock(&data->data_lock);
	}
	return (0);
}

static int	check_num_meals(t_data *data)
{
	int	i;
	int	n_philo_done;

	i = 0;
	n_philo_done = 0;
	pthread_mutex_lock(&data->data_lock);
	while (i < data->num_philo)
	{
		if (data->philo[i].qt_meals == data->num_meals)
			n_philo_done++;
		i++;
	}
	if (n_philo_done == data->num_philo)
	{
		data->l_status = STOP;
		pthread_mutex_unlock(&data->data_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->data_lock);
	return (0);
}

void	monitor_routine(t_data *data)
{
	while (1)
	{
		usleep(1000);
		if (check_status(data))
			return ;
		if (check_num_meals(data))
			return ;
	}
}
