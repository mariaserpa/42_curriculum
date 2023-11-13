/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:17:47 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/09 17:22:10 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char*str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

/*#include <stdio.h>

int	main(void)
{
	int	test1 = ft_strlen("Hello World");
	printf("%i\n", test1);
}*/
