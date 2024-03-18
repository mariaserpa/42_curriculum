/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:16:51 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/01/29 15:45:25 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/so_long.h"

int	ft_putnbr_base(int nbr, char*base)
{
	long int	n;
	long int	l;
	int			i;

	n = nbr;
	i = 0;
	l = ft_strlen(base);
	if (base)
	{
		if (n < 0)
		{
			i += ft_print_char('-');
			n *= -1;
		}
		if (n < l)
			i += ft_print_char(base[n]);
		if (n >= l)
		{
			i += ft_putnbr_base(n / l, base);
			i += ft_putnbr_base(n % l, base);
		}
	}
	if (i < 0)
		return (-1);
	return (i);
}
