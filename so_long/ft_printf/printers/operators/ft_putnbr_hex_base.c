/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:09:34 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/01/29 15:45:34 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/so_long.h"

int	ft_putnbr_hex_base(unsigned long long n, char*base)
{
	int	i;

	i = 0;
	if (n > 15)
	{
		i += ft_putnbr_hex_base(n / 16, base);
		i += ft_putnbr_hex_base(n % 16, base);
	}
	else
		i += ft_print_char(base[n]);
	return (i);
}
