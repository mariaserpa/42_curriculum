/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:19:55 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/17 11:35:10 by mrabelo-         ###   ########.fr       */
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

void	print_stack(t_stack *a); //retirar

/*command_swap*/
void	swap(t_stack**start);
void	sa(t_stack**a);
void	sb(t_stack**b);
void	ss(t_stack**a, t_stack**b);

/*command_rotate*/
void	rotate(t_stack**stack);
void	ra(t_stack**a);
void	rb(t_stack**b);
void	rr(t_stack**a, t_stack**b);

/*command_reverse*/
void	reverse_rotate(t_stack**stack);
void	rra(t_stack**a);
void	rrb(t_stack**b);
void	rrr(t_stack**a, t_stack**b);

/*command_push*/
void	push(t_stack**dest, t_stack**src);
void	pa(t_stack**a, t_stack**b);
void	pb(t_stack**b, t_stack**a);

/*error*/
void	print_error(t_stack**a, char**argv, bool flag);
int		error_syntax(char*str);
int		error_duplicates(t_stack*a, int n);

/*free*/
void	free_fake_argv(char**argv);
void	free_stack(t_stack**stack);

/*sort*/
void	sort_three(t_stack**a);
void	big_sort(t_stack**a, t_stack**b);

/*sort_utils_prep*/
void	prep_stack_a(t_stack*a, t_stack*b);
void	prep_stack_b(t_stack*a, t_stack*b);

/*sort_utils_check*/
void	check_index(t_stack*stack);
void	set_cheapest(t_stack*stack);
t_stack	*find_max(t_stack*stack);
t_stack	*find_min(t_stack*stack);
t_stack	*find_cheapest(t_stack*stack);

/*sort_utils_push*/
void	push_cheapest_to_b(t_stack**a, t_stack**b);
void	push_back_to_a(t_stack**a, t_stack**b);
void	prep_push(t_stack**stack, t_stack*top_node, char name_stack);

/*stack*/
void	start_stack(t_stack**a, char**argv, bool flag);
int		stack_size(t_stack*lst);
bool	check_sort(t_stack*a);
void	check_top(t_stack**a);

#endif