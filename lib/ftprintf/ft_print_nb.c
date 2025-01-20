/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:11:22 by ngeny             #+#    #+#             */
/*   Updated: 2023/11/30 17:32:55 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nb(int nb)
{
	int	outpout_len;

	outpout_len = ft_int_len(nb);
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else if (nb < 0)
	{
		nb = nb * -1;
		ft_print_char('-');
		ft_print_nb(nb);
	}
	else if (nb < 10)
	{
		ft_print_char(nb + '0');
	}
	else if (nb >= 10)
	{
		ft_print_nb(nb / 10);
		ft_print_nb(nb % 10);
	}
	return (outpout_len);
}
