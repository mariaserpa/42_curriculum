/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:41:35 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/05/07 14:51:30 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_countword(char *s, char c)
{
	int	i;
	int	word_count;
	int	new_word;

	if (s == 0)
		return (0);
	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		new_word = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
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

static char	*get_word(char*str, char s)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	i = 0;
	len = 0;
	while (str[cursor] == s)
		cursor++;
	while ((str[cursor + len] != s) && str[cursor + len])
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (!next_str)
		return (0);
	while ((str[cursor] != s) && str[cursor])
	{
		next_str[i] = str[cursor];
		i++;
		cursor++;
	}
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split_mod(char *str, char s)
{
	int		words;
	char	**dest;
	int		i;

	i = 0;
	words = ft_countword(str, s);
	if (!words)
		exit (1);
	dest = malloc(sizeof(char *) * (size_t)(words + 2));
	if (dest == 0)
		return (0);
	while (words-- >= 0)
	{
		if (i == 0)
		{
			dest[i] = malloc(sizeof(char));
			if (dest[i] == 0)
				return (0);
			dest[i++][0] = '\0';
			continue ;
		}
		dest[i++] = get_word(str, s);
	}
	dest[i] = 0;
	return (dest);
}
