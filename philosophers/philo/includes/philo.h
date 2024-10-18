/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:30:56 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/10/17 17:29:33 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

# define INPUT_ERROR_1 "All values must be positive numbers!"
# define INPUT_ERROR_2 "Number of philosophers exceeded"
# define INPUT_ERROR_3 "Wroung amount of arguments!"

typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				qt_meals;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				start;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_data;


void	arg_validation(int argc, char *argv[]);
void	pe_exit(t_data *data, char *msg, int code);

long	ft_custom_atol(const char*str);

void	pe_exit(t_data *data, char *msg, int code);

void	init_data(t_data *data, char *argv[]);
void	init_forks(t_data *data);
void	init_philo(t_data *data);

#endif