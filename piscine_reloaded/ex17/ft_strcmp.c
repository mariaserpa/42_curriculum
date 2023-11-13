/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:23:43 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/09 18:36:27 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char*s1, char*s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_strcmp("Hello", "Hello1"));
	printf("%d\n", ft_strcmp("Hello", "He"));
	printf("%d\n", ft_strcmp("He", "Hello"));
	printf("%d\n", ft_strcmp("Hello", "Hello"));
}*/
