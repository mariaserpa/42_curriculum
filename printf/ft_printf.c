/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:09:28 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/05 19:58:30 by mrabelo-         ###   ########.fr       */
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
		len += ft_print_string()

}


int	ft_printf(const char*input, ...)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			len +=
		}
		else
		{

		}
	}
}
