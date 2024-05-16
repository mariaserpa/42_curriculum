/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:40 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/04 22:55:09 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	n_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static long int	abs_value(int n)
{
	long int	nb;

	nb = 1;
	if (n < 0)
		nb *= -n;
	else
		nb *= n;
	return (nb);
}

char	*ft_itoa(int n)
{
	unsigned int		nb;
	int					sign;
	int					len;
	char				*dest;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = n_len(n);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	dest[len] = '\0';
	nb = abs_value(n);
	while (len > 0)
	{
		dest[len - 1] = '0' + nb % 10;
		nb /= 10;
		len--;
	}
	if (sign == 1)
		dest[0] = '-';
	return (dest);
}

/*#include <stdio.h>

int main()
{
	int num1 = 12345;
	int num2 = -9876;
	int num3 = 0;
	char *str1 = ft_itoa(num1);
	char *str2 = ft_itoa(num2);
	char *str3 = ft_itoa(num3);

	printf("Integer: %d, String: %s\n", num1, str1);
	printf("Integer: %d, String: %s\n", num2, str2);
	printf("Integer: %d, String: %s\n", num3, str3);

	free(str1);
	free(str2);
	free(str3);
	return (0);
}*/
