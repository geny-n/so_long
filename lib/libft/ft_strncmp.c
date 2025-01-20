/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:42:01 by ngeny             #+#    #+#             */
/*   Updated: 2023/11/07 11:42:01 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		dif;
	char	*str1;
	char	*str2;

	i = 0;
	dif = 0;
	str1 = (char *) s1;
	str2 = (char *) s2;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] != str2[i])
		{
			dif = (unsigned char)str1[i] - (unsigned char)str2[i];
			return (dif);
		}
		i++;
	}
	return (0);
}
