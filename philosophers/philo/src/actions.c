/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:56:13 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/10/23 14:25:43 by mrabelo-         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->data->data_lock);
	print_status(philo, "is sleeping");
	pthread_mutex_unlock(&philo->data->data_lock);
	usleep(philo->data->time_to_sleep * 1000);
	pthread_mutex_lock(&philo->data->data_lock);
	print_status(philo, "is thinking");
	pthread_mutex_unlock(&philo->data->data_lock);
	if (philo->time_to_eat > philo->time_to_die)
		usleep(100);
	else if (philo->time_to_die - philo->time_to_eat - philo->time_to_sleep < 0)
		usleep(100);
	else
		usleep((philo->time_to_die - philo->time_to_eat - \
			philo->time_to_sleep) / 2 * 100);
}
