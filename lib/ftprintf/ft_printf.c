/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:06:19 by ngeny             #+#    #+#             */
/*   Updated: 2024/02/29 12:28:20 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_format(const char format, va_list args, int output_len)
{
	if (format == 'c')
		output_len = ft_print_char(va_arg(args, int));
	else if (format == 's')
		output_len = ft_print_string(va_arg(args, char *));
	else if (format == 'p')
		output_len = ft_print_pointer(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		output_len = ft_print_nb(va_arg(args, int));
	else if (format == 'u')
		output_len = ft_print_unsigned(va_arg(args, unsigned int), format);
	else if (format == 'x' || format == 'X')
		output_len = ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		output_len = ft_print_char('%');
	else
		return (0);
	return (output_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		cur;
	int		output_len;

	cur = 0;
	output_len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[cur] != '\0')
	{
		if (format[cur] == '%' && format[cur + 1] != '\0')
		{
			output_len += find_format(format[cur + 1], args, output_len);
			cur++;
		}
		else
			output_len += ft_print_char(format[cur]);
		cur++;
	}
	va_end(args);
	return (output_len);
}
