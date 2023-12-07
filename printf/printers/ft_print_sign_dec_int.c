/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sign_dec_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:17:11 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/07 17:03:24 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_sign_dec_int(int n)
{
	int			i;
	long int	nbr;

	nbr = n;
	i = 0;
	i += ft_putnbr_base(n, "0123456789");
	if (i == 0 || i < 0)
		return (-1);
	return (i);
}

/*#include <stdio.h>
int main() {
    int number = -123;

    ft_print_sign_dec_int(number);
    printf("\n");
	printf("%d\n", number);
    return (0);
}*/
