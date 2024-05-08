/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:19:55 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/08 17:21:19 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "structures.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h> //tirar

void	print_arg_error(void);
void	print_error(t_stack**a, char**argv, bool flag);
int		error_syntax(char*str);
void	free_fake_argv(char**argv);
void	free_stack(t_stack**stack);
void	start_stack(t_stack**a, char**argv, bool flag);

#endif