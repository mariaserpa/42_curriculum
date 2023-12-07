/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:09:34 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/07 16:32:18 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

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

/*#include <stdio.h>
int	main()
{
	int num1 = 0x1A;
	ft_putnbr_hex_base(num1, "0123456789abcdef");
	printf("\n");
	printf("%x\n", num1);
}*/
