/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:43:18 by ngeny             #+#    #+#             */
/*   Updated: 2023/11/07 11:43:18 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*str2;

	i = 0;
	j = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!str1 && !len)
		return (NULL);
	if (str2[i] == '\0')
		return (str1);
	while (str1[i] && i < len)
	{
		while (str1[i + j] == str2[j] && i + j < len)
		{
			if (str2[j + 1] == '\0')
				return (str1 + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
