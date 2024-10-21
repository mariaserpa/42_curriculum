/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malu <malu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:56:13 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/10/21 18:52:08 by malu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_one_philo_case(t_philo *philo)
{
	if (philo->data->num_philo == 1)
	{
		pthread_mutex_lock(&philo->data->data_lock);
		print_status(philo, "has taken a fork");
		usleep(philo->time_to_die * 1000);
		print_status(philo, "died");
		philo->data->l_status = DEAD;
		pthread_mutex_unlock(&philo->data->data_lock);
	}
}

void	prepare_to_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (philo->qt_meals == 0)
			usleep(philo->time_to_eat * 1000);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		if (philo->qt_meals == 0 && philo->data->num_philo % 2 != 0 \
			&& philo->id == 1)
			usleep(philo->time_to_eat * 1000);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_lock);
	philo->t_lastmeal = time_in_millisec();
	print_status(philo, "is eating");
	philo->qt_meals++;
	pthread_mutex_unlock(&philo->data->data_lock);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleep_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
	print_status(philo, "is thinking");
	usleep((philo->time_to_die - philo->time_to_eat - \
			philo->time_to_sleep) / 2 * 1000);
}
