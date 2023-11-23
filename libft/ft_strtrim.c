/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:18:54 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/23 16:30:54 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const*s1, char const*set)
{
	size_t	start;
	size_t	end;
	char	*dest;

	if (s1 == 0)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	dest = ft_substr(s1, start, end - start + 1);
	return (dest);
}
/*#include <stdio.h>

int main()
{
	char const *input = "//test string//";
	char const *set = "/";

	printf("Original String: \"%s\"\n", input);
	printf("Set: \"%s\"\n", set);

	char *trimmed = ft_strtrim(input, set);

	if (trimmed == NULL)
	{
		printf("Result: NULL (Invalid input)\n");
	}
	else
	{
		printf("Trimmed String: \"%s\"\n", trimmed);
		free(trimmed);
	}
	return (0);
}*/
