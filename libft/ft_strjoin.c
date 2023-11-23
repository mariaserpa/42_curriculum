/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:18:22 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/23 14:18:34 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const*s1, char const*s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		dest[j] = s2[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

/*#include <stdio.h>

int	main()
{
	const char *s1 = "Hello, ";
	const char *s2 = "world!";
	char *result = ft_strjoin(s1, s2);
	
	if (result != 0) 
	{
        	printf("Joined string: %s\n", result);
        	free(result); // Remember to free allocated memory
    	}
	else
	{
        	printf("Memory allocation failed.\n");
	}

	return (0);
}*/
