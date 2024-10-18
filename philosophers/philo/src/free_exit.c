/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:54:30 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/10/17 16:54:45 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	pe_exit(t_data *data, char *msg, int code)
{
	if (data)
	{
		if (data->forks)
			free_forks();
		if (data->philo)
			free_philo();
		//pthread_mutex_destroy();
		//pthread_mutex_destroy();
		free(data);
	}
	if (msg)
		printf("%s\n", msg);
	exit(code);
}

