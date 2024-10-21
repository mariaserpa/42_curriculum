/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malu <malu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:30:56 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/10/22 01:01:26 by malu             ###   ########.fr       */
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

# define ALIVE 0
# define DEAD 1
# define STOP 2

typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				qt_meals;
	long			t_lastmeal;
	pthread_t		td_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				l_status;
	long			t_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	data_lock;
	pthread_mutex_t	print_lock;
	t_philo			*philo;
}	t_data;

void	arg_validation(int argc, char *argv[]);

long	ft_custom_atol(const char*str);
long	time_in_millisec(void);
void	print_status(t_philo *philo, char *msg);
void	join_threads(t_data *data);
int		check_philo(t_philo *philo);

void	pe_exit(t_data *data, char *msg, int code);
void	free_structure(t_data *data);

void	init_data(t_data *data, char *argv[]);
void	init_forks(t_data *data);
void	init_philo(t_data *data);

void	start_routine(t_data *data);
void	monitor_routine(t_data *data);

void	check_one_philo_case(t_philo *philo);
void	prepare_to_eat(t_philo *philo);
void	eat(t_philo *philo);
void	sleep_think(t_philo *philo);

#endif
