/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:41:35 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/23 18:37:23 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const*s, char c)
{
	size_t	i;
	size_t	word_count;

	if (s == 0)
		return (0);
	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			word_count++;
		}
		i++
	}
	return (word_count);
}

char	**ft_split(char const*s, char c)
{
	size_t	i;
	size_t	j;
	char	**dest;

	dest = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (s == 0 || dest == 0)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{

	}
}
