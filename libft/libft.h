/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:38:10 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/11/21 14:08:11 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void		ft_bzero(void*s, size_t n);
void		*ft_memchr(const void*s, int c, size_t n);
void		*ft_memcpy(void *restrict dest, const void *restrict src, size_t n);
void		*ft_memmove(void*dest, const void*src, size_t len);
void		*ft_memset(void*s, int c, size_t n);

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(const char*str);
int			ft_memcmp(const void*s1, const void*s2, size_t n);
int			ft_strncmp(const char*s1, const char*s2, size_t n);

char		*ft_strdup(const char*src);
char		*ft_strchr(const char*s, int c);
char		*ft_strrchr(const char*s, int c);
char		*ft_strnstr(const char*s, const char*t, size_t len);

size_t		ft_strlen(const char*s);
size_t		ft_strlcat(char*dest, const char*src, size_t n);
size_t		ft_strlcpy(char*dest, const char*src, size_t n);

#endif
