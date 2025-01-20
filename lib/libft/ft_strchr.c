/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:39:15 by ngeny             #+#    #+#             */
/*   Updated: 2023/11/07 11:39:15 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ret;
	char	set;

	i = 0;
	ret = (char *)str;
	set = (unsigned char)c;
	while (ret[i] != '\0')
	{
		if (*ret == set)
			return (ret);
		ret++;
	}
	if (*ret == set)
		return (ret);
	return (NULL);
}
