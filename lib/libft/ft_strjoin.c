/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:54:03 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/29 19:24:26 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	str1 = (char *) s1;
	str2 = (char *) s2;
	i = 0;
	j = 0;
	dest = NULL;
	if (!s1)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2)) + 1);
	if (dest == NULL)
		return (NULL);
	while (str1[i])
	{
		dest[i] = str1[i];
		i++;
	}
	while (str2[j])
		dest[i++] = str2[j++];
	dest[i] = '\0';
	return (dest);
}
