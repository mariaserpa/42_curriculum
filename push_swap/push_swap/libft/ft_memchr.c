/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:02:23 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/16 18:02:56 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

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
