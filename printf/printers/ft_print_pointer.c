/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:00:43 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/07 13:47:23 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_pointer(void*p_adr)
{
	int				i;
	unsigned long	adr;
	char			*str;

	adr = (unsigned long)p_adr;
	i = ft_print_str("0x");
	if (i < 0)
		return (-1);
	str = ft_itoa_base();
	i += ft_print_str(str);
	free(str);
	if (i < 0)
		return (-1);
	return (i);
}

#include <stdio.h>
int main() {
    uintptr_t ptr_value = (uintptr_t)0x7fff5fbff700;

    printf("Pointer value: \n");
    ft_print_pointer(ptr_value);
	printf("%p", ptr_value);
    printf("\n");
    return (0);
}
