/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:09:28 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/09 15:46:28 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char*str, va_list args, int i)
{
	int	len;

	len = 0;
	if (str[i] == 'c')
		len += ft_print_char((char) va_arg(args, int));
	else if (str[i] == 's')
		len += ft_print_str((char *) va_arg(args, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		len += ft_print_sign_dec_int((int) va_arg(args, int));
	else if (str[i] == 'p')
		len += ft_print_pointer((void *) va_arg(args, void *));
	else if (str[i] == 'u')
		len += ft_print_unsign_dec_int(
				(unsigned int) va_arg(args, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		len += ft_print_unsign_hex_int(
				(unsigned int) va_arg(args, unsigned int), str[i]);
	else if (str[i] == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char*input, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, input);
	i = 0;
	len = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			len += ft_format(input, args, ++i);
			if (len < 0)
				return (-1);
		}
		else
		{
			len += ft_print_char(input[i]);
			if (len < 0)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*#include <stdio.h>
int main() {
    int num = 42;
    char *str = "Hello, world!";
    void *ptr = &num;

    ft_printf("Printing a character: %c", 'A');
	printf("\n");
    ft_printf("Printing a string: %s", str);
	printf("\n");
    ft_printf("Printing a decimal number: %d", num);
	printf("\n");
    ft_printf("Printing a pointer: %p", ptr);
	printf("\n");
    ft_printf("Printing an unsigned decimal number: %u", 12345);
	printf("\n");
    ft_printf("Printing a hexadecimal number: %x", 255);
	printf("\n");
	ft_printf(" %c %c %c ", '0', 0, '1');
	printf("\n");
	printf(" %c %c %c ", '0', 0, '1');
    return (0);
}*/