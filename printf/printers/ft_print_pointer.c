/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:00:43 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/07 16:32:21 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

/*#include <stdio.h>
int main() {
	int val = 42;
    int *num = &val;
	ft_print_pointer(num);
	printf("\n");
	printf("%p\n", num);

    int *num2 = 0;
	ft_print_pointer(num2);
	printf("\n");
	printf("%p\n", num2);
	return (0);
}*/
