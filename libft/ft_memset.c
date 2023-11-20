/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:45:38 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/14 16:15:36 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void*s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		*p = (unsigned char)c;
		i++;
		p++;
	}
	return (s);
}

/*#include <stdio.h>

int	main() 
{
    char str[20];
    int fillValue = 'A';
    size_t numChars = 10;

    ft_memset(str, fillValue, numChars);
    printf("Filled string: %s\n", str);

    return (0);
}*/
