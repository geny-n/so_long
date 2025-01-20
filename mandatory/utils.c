/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:46:59 by ngeny             #+#    #+#             */
/*   Updated: 2024/05/15 23:45:55 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*error_arg(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
	{
		ft_printf("ERROR arguments\n");
		return (NULL);
	}
	str = ft_strrchr(argv[1], '.');
	if (str == NULL)
	{
		ft_printf("ERROR no map\n");
		return (NULL);
	}
	else
		return (str);
	return (NULL);
}

int	map_height(char **map)
{
	int	cur;

	cur = 0;
	while (map[cur])
		cur++;
	return (cur);
}

int	map_lenght(char **map)
{
	int	len;

	len = 0;
	len = ft_strlen(map[0]);
	return (len);
}
