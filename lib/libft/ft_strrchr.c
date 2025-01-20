/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:44:27 by ngeny             #+#    #+#             */
/*   Updated: 2023/11/07 11:44:27 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*ret;
	char	set;

	ret = (char *)str;
	set = (unsigned char)c;
	i = ft_strlen(ret);
	while (ret[i])
		i++;
	while (i >= 0)
	{
		if (ret[i] == set)
			return (ret + i);
		i--;
	}
	if (set == '\0')
		return (ret);
	return (NULL);
}
