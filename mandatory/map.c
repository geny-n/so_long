/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:57:19 by ngeny             #+#    #+#             */
/*   Updated: 2024/05/15 23:45:51 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	verif_empty_line(char *one_line)
{
	int	i;

	i = 0;
	while (one_line[i])
	{
		if (one_line[i] == '\n' && one_line[i + 1] == '\n')
		{
			ft_printf("ERROR empty line\n");
			return (0);
		}
		else if (one_line[i] == '\n' && one_line[i + 1] == ' ')
		{
			ft_printf("ERROR space line\n");
			return (0);
		}
		if (one_line[0] != '1')
		{
			ft_printf ("map null\n");
			return (0);
		}
		i++;
	}
	return (1);
}

char	*read_map(int fd)
{
	char	*one_line;
	char	*line;

	line = "";
	one_line = ft_strdup("");
	line = get_next_line(fd);
	if (!line)
		ft_printf("Empty file\n");
	while (line)
	{
		one_line = ft_strjoin_gnl(one_line, line);
		free(line);
		line = get_next_line(fd);
	}
	if (verif_empty_line(one_line) == 0)
		return (free(one_line), NULL);
	return (one_line);
}

char	**get_map(int fd)
{
	char	*map_one;
	char	**map;

	map_one = NULL;
	map = NULL;
	map_one = read_map(fd);
	if (!map_one)
		ft_printf("ERROR map\n");
	else
		map = ft_split(map_one, '\n');
	free(map_one);
	return (map);
}

char	**check_map(int fd, t_data *data)
{
	data->map = get_map(fd);
	if (data->map == NULL)
		return (0);
	init(data);
	if (map_rectagle(data) == 0
		|| check_countain(data) == 0
		|| verif_ecp(data) == 0
		|| check_side_up_down(data) == 0
		|| check_valid_path(data) == 0)
	{
		free_map(data->map);
		return (NULL);
	}
	return (data->map);
}
