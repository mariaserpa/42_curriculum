/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:56:12 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/29 16:26:31 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const*s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (0);
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>

char	add_one(unsigned int index, char c)
{
	return (c + 1);
}

int	main()
{
	const char *input_string = "Hello, World!";
	printf("Original string: %s\n", input_string);
	char *result = ft_strmapi(input_string, &add_one);
	printf("Mapped string (adding 1 to each character): %s\n", result);
	free(result);
	return (0);
}*/
