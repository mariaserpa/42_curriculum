/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:00:43 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/01/29 15:43:50 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	ft_print_pointer(void*p_adr)
{
	int					i;
	unsigned long long	adr;

	i = 0;
	if (p_adr == 0)
		i += ft_print_str("(nil)");
	else
	{
		adr = (unsigned long long)p_adr;
		i = ft_print_str("0x");
		if (i < 0)
			return (-1);
		i += ft_putnbr_hex_base(adr, "0123456789abcdef");
	}
	if (i < 0)
		return (-1);
	return (i);
}
