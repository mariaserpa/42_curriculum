/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:02:23 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/17 14:03:24 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void*s, int c, size_t n)
{
	size_t			i;
	unsigned char	temp_c;
	unsigned char	*temp_s;

	i = 0;
	temp_c = (unsigned char)c;
	temp_s = (unsigned char *)s;
	while (i < n)
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
	size_t	n = 7;
	char *result = ft_memchr(str, target_char, n);

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
