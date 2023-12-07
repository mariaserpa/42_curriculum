/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:33:50 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/07 17:20:43 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int			ft_printf(const char*input, ...);
int			ft_print_char(char c);
int			ft_print_str(char*s);
int			ft_print_sign_dec_int(int n);
int			ft_print_pointer(void*p_adr);
int			ft_print_unsign_dec_int(unsigned int n);
int			ft_print_unsign_hex_int(unsigned int n, char c);
int			ft_putnbr_base(int nbr, char*base);
int			ft_putnbr_hex_base(unsigned long long n, char*base);
int			ft_putnbr_unsign(unsigned int n, char*base);

size_t		ft_strlen(const char*s);

#endif
