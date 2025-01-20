/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:11:30 by ngeny             #+#    #+#             */
/*   Updated: 2023/11/30 17:20:59 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nb, const char format)
{
	int	output_len;

	output_len = ft_unsigned_len(nb, format);
	if (nb < 10)
	{
		ft_print_char(nb + '0');
	}
	else if (nb >= 10)
	{
		ft_print_unsigned(nb / 10, format);
		ft_print_unsigned(nb % 10, format);
	}
	return (output_len);
}
