/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:38:44 by ngeny             #+#    #+#             */
/*   Updated: 2024/03/06 11:51:19 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	feel_ptr(int len, int nb, char *ptr)
{
	if (nb == 0)
		ptr[0] = '0';
	while (nb != 0)
	{
		ptr[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;

	len = len_nb(n);
	ptr = NULL;
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		ptr[0] = '-';
		ptr[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		ptr[0] = '-';
		n = n * -1;
	}
	feel_ptr(len, n, ptr);
	ptr[len] = '\0';
	return (ptr);
}
