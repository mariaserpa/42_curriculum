/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:38:32 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/17 17:06:19 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

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

void	*ft_calloc(size_t number, size_t size)
{
	void	*dest;

	dest = (void *)malloc(sizeof(number * size));
	if (dest == 0)
		return (0);
	ft_bzero(dest, number * size);
	return (dest);
}

/*#include <stdio.h>

int	main()
{
	int	*arr = (int *)ft_calloc(5, sizeof(int));

	if (arr != NULL)
	{
		printf("Allocated memory content:\n");
		for (size_t i = 0; i < 5; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}*/
