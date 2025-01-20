/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:55:13 by ngeny             #+#    #+#             */
/*   Updated: 2023/11/13 15:23:41 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s_dest;
	char	*s_src;

	i = 0;
	s_dest = (char *)dest;
	s_src = (char *)src;
	if (s_dest == 0 && s_src == 0)
		return (NULL);
	if (s_src < s_dest)
	{
		while (n--)
			s_dest[n] = s_src[n];
	}
	else
	{
		while (i < n)
		{
			s_dest[i] = s_src[i];
			i++;
		}
	}
	return (s_dest);
}
