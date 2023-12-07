/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unknown_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:54:44 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/07 11:02:32 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*ft_check_numb_system(long int nbr)
{
	char	*base;

	if ((nbr & 0xFFFFFFF0) == 0x0)
	{
		if ((nbr & 0xF0) == 0 || (nbr & 0xF0) == 0xF0)
			base = "0123456789abcdef";
		else
			base = "0123456789ABCDEF";
	}
	else if ((nbr & 0xFF) == nbr)
		base = "01234567";
	else
		base = "0123456789";
	return (base);
}

int	ft_putnbr_unknown_base(long int n)
{
	int			i;
	int			len;
	char		*base;

	i = 0;
	base = ft_check_numb_system(n);
	len = ft_strlen(base);
	if (base)
	{
		if (n < 0)
		{
			i += ft_print_char('-');
			n *= -1;
		}
		if (n < len)
			i += ft_print_char(base[n]);
		if (n >= len)
		{
			i += ft_putnbr_unknown_base(n / len);
			i += ft_putnbr_unknown_base(n % len);
		}
	}
	if (i < 0)
		return (-1);
	return (i);
}

#include <stdio.h>
int	main() 
{
	long int num1 = 0x1A;
	ft_putnbr_unknown_base(num1);
	printf("\n");

	long int num2 = -789;
	ft_putnbr_unknown_base(num2);
	printf("\n");

	long int num3 = 025;
	ft_putnbr_unknown_base(num3);
	printf("\n");

	long int num4 = -987654321;
	ft_putnbr_unknown_base(num4);
	printf("\n");
	return (0);
}