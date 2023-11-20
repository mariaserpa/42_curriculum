/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:15:40 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/16 16:26:04 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void*dest, const void*src, size_t len)
{
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	i = 0;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (!temp_dest && !temp_src)
		return (0);
	if (temp_src < temp_dest)
	{
		i = len;
		while (i-- > 0)
			temp_dest[i] = temp_src[i];
	}
	else
	{
		while (i < len)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	return (dest);
}

/*#include <stdio.h>

int	main()
{
	// Test 1: Overlapping memory regions
	char str1[] = "Hello, World!";
	char buffer1[20];

	ft_memmove(buffer1, str1 + 6, 8);
	printf("Scenario 1 - Overlapping: %s\n", buffer1);

	// Test 2: Non-overlapping memory regions
	char str2[] = "Hello, World!";
	char buffer2[20];

	ft_memmove(buffer2, str2, 8);
	printf("iScenario 2 - Non-overlapping: %s\n", buffer2);

	// Test 3: src is bigger than dst
	char src[] = "This is a larger string";
	char dst[10];

	printf("Before memmove: %s\n", dst);
	ft_memmove(dst, src, 9);
	printf("After memmove: %s\n", dst);
	return (0);
}*/
