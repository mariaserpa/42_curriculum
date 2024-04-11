/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:16:43 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/01/29 15:44:15 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	ft_print_str(char*s)
{
	int	i;

	i = 0;
	if (!s)
	{
		i += ft_print_str("(null)");
		return (i);
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
