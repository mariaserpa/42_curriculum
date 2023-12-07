/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:51:54 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/07 12:12:04 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_putnbr_unsign(unsigned int n, char*base)
{
	int				i;
	unsigned int	l;

	i = 0;
	l = ft_strlen(base);
	if (base)
	{
		if (n >= l)
		{
			i += ft_putnbr_unsign(n / l, base);
			i += ft_putnbr_unsign(n % l, base);
		}
		if (n < l)
			i += ft_print_char(base[n]);
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

	ft_putnbr_unsign(num1, base);
	printf("\n");
	printf("%u\n", num1);
}*/
