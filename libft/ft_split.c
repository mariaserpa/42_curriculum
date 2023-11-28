/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:41:35 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/28 17:14:49 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const*s, char c)
{
	size_t	i;
	size_t	word_count;
	int		new_word;

	if (s == 0)
		return (0);
	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		new_word = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if (new_word == 0)
			{
				word_count++;
				new_word = 1;
			}
			i++;
		}
	}
	return (word_count);
}

static size_t	try_malloc(char**dest, size_t pos, size_t size)
{
	size_t	i;

	i = 0;
	dest[pos] = malloc(size);
	if (dest[pos] == 0)
	{
		while (i < pos)
		{
			free(dest[i++]);
		}
		free(dest);
		return (1);
	}
	return (0);
}

static size_t	ft_fill_words(char**dest, char const*s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (try_malloc(dest, i, len + 1))
				return (1);
			ft_strlcpy(dest[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const*s, char c)
{
	size_t	words;
	char	**dest;

	words = ft_countword(s, c);
	dest = (char **)malloc(sizeof(char *) * (words + 1));
	if (s == 0 || dest == 0)
		return (0);
	if (ft_fill_words(dest, s, c))
		return (0);
	dest[words] = 0;
	return (dest);
}

/*#include <stdio.h>

int	main()
{
	char	*s = "   lorem   ipsum dolor     sit amet";
	char	**v = ft_split(s, ' ');

	while (*v)
		printf("%s\n", *v++);
}*/
