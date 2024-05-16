/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:02:41 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/16 18:03:27 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	temp_c;
	char	*temp_s;

	temp_c = (char)c;
	temp_s = (char *)s;
	i = ft_strlen(temp_s);
	if (temp_s[i] == '\0' && temp_c == '\0')
		return (temp_s + i);
	while (i >= 0)
	{
		if (temp_s[i] == temp_c)
			return (temp_s + i);
		i--;
	}
	return (0);
}
