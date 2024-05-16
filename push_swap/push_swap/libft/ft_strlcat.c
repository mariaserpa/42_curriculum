/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:27:17 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/04 22:55:09 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_strlcat(char*dest, const char*src, size_t n)
{
	size_t	i;
	size_t	res;
	size_t	len_src;
	size_t	len_dest;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	res = 0;
	if (n > len_dest)
		res = len_dest + len_src;
	else
		res = len_src + n;
	i = 0;
	while (src[i] && (len_dest + 1) < n)
	{
		dest[len_dest] = src[i];
		len_dest++;
		i++;
	}
	dest[len_dest] = '\0';
	return (res);
}

/*#include <stdio.h>

int	main()
{
	char destination[20] = "Hello";
	char source[] = " world!";

	printf("Concatenated string: %zu\n", ft_strlcat(destination, source, 20));
	printf("Length of concatenated string: %s\n", destination);
	return (0);
}*/
