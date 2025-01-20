/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:11:26 by ngeny             #+#    #+#             */
/*   Updated: 2023/11/30 17:32:33 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long str)
{
	int	output_len;

	output_len = ft_long_len(str);
	if (str)
	{
		output_len += ft_print_char('0');
		output_len += ft_print_char('x');
		ft_long_hex(str);
	}
	else
	{
		ft_print_string("(nil)");
		return (5);
	}
	return (output_len);
}
