/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:34:26 by ngeny             #+#    #+#             */
/*   Updated: 2023/11/07 11:34:26 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	set;
	unsigned char	*ret;

	i = 0;
	set = (unsigned char ) c;
	ret = (unsigned char *) str;
	while (i < n)
	{
		if (ret[i] == set)
			return (ret + i);
		i++;
	}
	return (NULL);
}
