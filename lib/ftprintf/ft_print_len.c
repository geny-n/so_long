/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:51:08 by ngeny             #+#    #+#             */
/*   Updated: 2024/02/29 11:54:52 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_len(int nb)
{
	int	output_len;

	output_len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		output_len++;
	while (nb != 0)
	{
		nb = nb / 10;
		output_len++;
	}
	return (output_len);
}

int	ft_unsigned_len(unsigned int nb, const char format)
{
	int	output_len;

	output_len = 0;
	if (nb == 0)
		return (1);
	if (nb <= 0)
		output_len++;
	while (nb != 0)
	{
		if (format == 'u')
		{
			nb = nb / 10;
			output_len++;
		}
		else if (format == 'x' || format == 'X')
		{
			nb = nb / 16;
			output_len++;
		}
	}
	return (output_len);
}

int	ft_long_len(unsigned long nb)
{
	int	output_len;

	output_len = 0;
	if (nb == 0)
		return (1);
	if (nb <= 0)
		output_len++;
	while (nb != 0)
	{
		nb = nb / 16;
		output_len++;
	}
	return (output_len);
}
