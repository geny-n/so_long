/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:11:16 by ngeny             #+#    #+#             */
/*   Updated: 2023/11/30 17:35:17 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nb, const char format)
{
	int	output_put;

	output_put = ft_unsigned_len(nb, format);
	if (nb >= 16)
	{
		ft_print_hex(nb / 16, format);
		ft_print_hex(nb % 16, format);
	}
	else if (nb < 10)
		ft_print_char(nb + '0');
	else if (format == 'x')
		ft_print_char(nb - 10 + 'a');
	else if (format == 'X')
		ft_print_char(nb - 10 + 'A');
	return (output_put);
}

int	ft_long_hex(unsigned long nb)
{
	int	output_put;

	output_put = ft_long_len(nb);
	if (nb >= 16)
	{
		ft_long_hex(nb / 16);
		ft_long_hex(nb % 16);
	}
	else if (nb < 10)
		ft_print_char(nb + '0');
	else
		ft_print_char(nb - 10 + 'a');
	return (output_put);
}
