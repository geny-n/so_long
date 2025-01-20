/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:46:59 by ngeny             #+#    #+#             */
/*   Updated: 2024/05/28 21:40:36 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*bonus_error_arg(int argc, char **argv)
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

void	bonus_check_image(t_data *data, char *image)
{
	int	fd;

	fd = open(image, O_RDONLY, 0777);
	if (fd == -1)
	{
		ft_printf("ERROR no image %s\n", image);
		bonus_free_map(data->map);
		exit(1);
	}
	return ;
}

int	bonus_map_height(char **map)
{
	int	cur;

	cur = 0;
	while (map[cur])
		cur++;
	return (cur);
}

int	bonus_map_lenght(char **map)
{
	int	len;

	len = 0;
	len = ft_strlen(map[0]);
	return (len);
}
