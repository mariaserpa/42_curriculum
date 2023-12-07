/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:16:51 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/07 12:15:05 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

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

/*#include <stdio.h>
int	main() 
{
	char *base = "0123456789";
	int num1 = 123456;

	ft_putnbr_base(num1, base);
	printf("\n");
	printf("%i\n", num1);

	int num2 = -789;
	ft_putnbr_base(num2, base);
	printf("\n");
	printf("%i\n", num2);

	int num3 = 025;
	ft_putnbr_base(num3, base);
	printf("\n");
	printf("%i\n", num3);

	int num4 = -987654321;
	ft_putnbr_base(num4, base);
	printf("\n");
	printf("%i\n", num4);
	return (0);
}*/