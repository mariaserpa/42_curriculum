/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sign_dec_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:17:11 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/01/29 15:44:01 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	ft_print_sign_dec_int(int n)
{
	int			i;
	long int	nbr;

	nbr = n;
	i = 0;
	i += ft_putnbr_base(nbr, "0123456789");
	if (i == 0 || i < 0)
		return (-1);
	return (i);
}
