/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:36:56 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/21 16:05:17 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void*dest, const void*src, size_t n)
{
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (!dest && !src)
		return (0);
	i = 0;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (i < n)
	{
		*temp_dest = *temp_src;
		temp_dest++;
		temp_src++;
		i++;
	}
	return (dest);
}

/*#include <stdio.h>

int	main()
{
	char source[] = "Hello, World!";
	char destination[20];

	ft_memcpy(destination, source, 14);

	printf("Copied string: %s\n", destination);

	return (0);
}*/
