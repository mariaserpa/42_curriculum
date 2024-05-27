/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:35:16 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/26 11:20:20 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	main(int argc, char**argv, char**envp)
{
	if (argc < 5 || (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc < 6))
		print_error("Error: Invalid number of arguments\n");
	else if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc >= 6)
		here_doc_case(argc, argv, envp);
	else
		commands_only_case(argc, argv, envp);
	return (0);
}
