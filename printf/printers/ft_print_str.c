/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:16:43 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/07 18:28:52 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_str(char*s)
{
	int	i;

	i = 0;
	if (!s)
	{
		i += ft_print_str("(null)");
		return (i);
	}
	else
	{
		while (s[i])
		{
			if (ft_print_char(s[i]) == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}

/*#include <stdio.h>
int main() {
    char *message = 0;
	int result;

	result = ft_print_str(message);
    printf("%i\n", result);
	result = printf("%s", message);
	printf("%i\n", result);

    return (0);
}*/
