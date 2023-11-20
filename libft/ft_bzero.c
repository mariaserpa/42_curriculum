/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:34:59 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/16 14:35:21 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void*s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		*p = 0;
		i++;
		p++;
	}
}

/*#include <stdio.h>

int	main() 
{
    char str[20];
    size_t numChars = 10;

    ft_bzero(str, numChars);
    printf("Filled string: %s\n", str);

    return (0);
}*/
