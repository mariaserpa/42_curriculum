/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:42:32 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/17 15:24:23 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char*s, const char*t, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	i = 0;
	str = (char *)s;
	to_find = (char *)t;
	if (to_find[i] == '\0' || to_find == 0)
		return (str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < len)
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
/*#include <stdio.h>

int	main()
{
	const char str[] = "42 1337 Network 2021 piscine Benguerir Khouribga";
	const char find[] = "piscine";
	char	*result = ft_strnstr(str, find, 35);

	if (result != 0)
	{
		printf("Substring found starting at: %ld\n", result - str);
		printf("Substring found: %s\n", result);
	}
	else
	{
		printf("Substring not found.\n");
	}
}*/
