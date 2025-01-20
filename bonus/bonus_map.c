/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:57:19 by ngeny             #+#    #+#             */
/*   Updated: 2024/05/29 15:40:43 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	bonus_verif_empty_line(char *one_line)
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

char	*bonus_read_map(int fd)
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
	if (bonus_verif_empty_line(one_line) == 0)
		return (free(one_line), NULL);
	return (one_line);
}

char	**bonus_get_map(int fd)
{
	char	*map_one;
	char	**map;

	map_one = NULL;
	map = NULL;
	map_one = bonus_read_map(fd);
	if (!map_one)
		ft_printf("ERROR map\n");
	else
		map = ft_split(map_one, '\n');
	free(map_one);
	return (map);
}

char	**map_new_line(t_data *data)
{
	int		y;
	char	*one_line;

	y = 0;
	one_line = ft_strdup("");
	while (data->map[y])
	{
		one_line = ft_strjoin_gnl(one_line, data->map[y]);
		one_line = ft_strjoin_gnl(one_line, "\n");
		y++;
	}
	y = 0;
	while (y < data->map_w)
	{
		one_line = ft_strjoin_gnl(one_line, "0");
		y++;
	}
	bonus_free_map(data->map);
	data->map = ft_split(one_line, '\n');
	free(one_line);
	data->map_h = bonus_map_height(data->map);
	data->map_w = bonus_map_lenght(data->map);
	return (data->map);
}

char	**bonus_check_map(int fd, t_data *data)
{
	data->map = bonus_get_map(fd);
	if (data->map == NULL)
		return (0);
	bonus_init(data);
	if (bonus_map_rectagle(data) == 0
		|| bonus_check_countain(data) == 0
		|| bonus_verif_ecp(data) == 0
		|| bonus_check_side_up_down(data) == 0
		|| bonus_check_valid_path(data) == 0)
	{
		bonus_free_map(data->map);
		return (NULL);
	}
	map_new_line(data);
	return (data->map);
}
