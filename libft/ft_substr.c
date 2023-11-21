/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:44:25 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/21 18:17:32 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const*s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*#include <stdio.h>

int main()
{
	const char *original_string = "This is a test string for substr function";
	unsigned int start_index = 5;
	size_t length = 10;

	char *sub_string = ft_substr(original_string, start_index, length);

	printf("Original string: %s\n", original_string);
	printf("%zu\n", ft_strlen(sub_string));
	return (0);
}*/
