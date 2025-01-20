/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:05:18 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/06 11:52:57 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_int_len(int nb);
int	ft_unsigned_len(unsigned int nb, const char format);
int	ft_long_len(unsigned long nb);
int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_pointer(unsigned long str);
int	ft_print_nb(int nb);
int	ft_print_unsigned(unsigned int nb, const char format);
int	ft_print_hex(unsigned int nb, const char format);
int	ft_long_hex(unsigned long nb);

#endif