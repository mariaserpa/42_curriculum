/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:28:50 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/16 18:49:58 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char*s, int c)
{
	int		i;
	char	temp_c;
	char	*temp_s;

	i = 0;
	temp_c = (char)c;
	temp_s = (char *)s;
	if (temp_s[i] == '\0' && temp_c == '\0')
		return (temp_s + i);
	while (temp_s[i] != '\0')
	{
		if (temp_s[i] == temp_c)
			return (temp_s + i);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int main() {
	const char *str = "Hello, world!";
	int target_char = 'o';
	char *result = ft_strchr(str, target_char);

	if (result != 0)
	{
		printf("Found character '%c' at position: %ld\n", target_char, result - str);
	}
	else
	{
		printf("Character '%c' not found in the string.\n", target_char);
	}

	return (0);
}*/
