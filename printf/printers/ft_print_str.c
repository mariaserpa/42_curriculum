/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:16:43 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/06 21:55:50 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_str(char*s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_print_str("(null)");
	}
	else
	{
		while (s[i])
		{
			if (ft_print_char(s[i]) == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}
