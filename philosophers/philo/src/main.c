/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malu <malu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:20:51 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/10/22 00:07:09 by malu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	arg_validation(int argc, char *argv[])
{
	int	i;

	if (argc == 5 || argc == 6)
	{
		i = 1;
		while (i < argc)
		{
			if ((int)ft_custom_atol(argv[i]) <= 0)
				pe_exit(NULL, INPUT_ERROR_1, EXIT_FAILURE);
			if (i == 1 && (int)ft_custom_atol(argv[i]) > 200)
				pe_exit(NULL, INPUT_ERROR_2, EXIT_FAILURE);
			i++;
		}
	}
	else
		pe_exit(NULL, INPUT_ERROR_3, EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	arg_validation(argc, argv);
	init_data(&data, argv);
	init_forks(&data);
	init_philo(&data);
	start_routine(&data);
	monitor_routine(&data);
	join_threads(&data);
	pe_exit(&data, NULL, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
