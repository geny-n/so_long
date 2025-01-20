/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:33:26 by ngeny             #+#    #+#             */
/*   Updated: 2024/06/03 19:22:59 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**duplicate_map(t_data *data)
{
	int		i;
	char	**dup_map;

	i = 0;
	dup_map = malloc(sizeof(char *) * (data->map_h));
	if (dup_map == NULL)
		return (NULL);
	while (data->map[i])
	{
		dup_map[i] = ft_strdup(data->map[i]);
		i++;
	}
	return (dup_map);
}

int	check_all_collect(char **copy_map, t_data *data, int *flag)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map_h)
	{
		j = 0;
		while (j < data->map_w)
		{
			if (*flag == 0)
			{
				ft_printf ("ERROR no path\n");
				return (0);
			}
			if (copy_map[i][j] == 'C')
			{
				ft_printf ("ERROR no path collectible\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_first(char **copy_map, int pos_x, int pos_y, int *flag)
{
	if (copy_map[pos_y][pos_x] == '1' || copy_map[pos_y][pos_x] == 'x')
		return ;
	if (copy_map[pos_y][pos_x] == 'E')
	{	
		*flag = 1;
		return ;
	}
	if (copy_map[pos_y][pos_x] == 'C' || copy_map[pos_y][pos_x] == '0'
		|| copy_map[pos_y][pos_x] == 'P')
		copy_map[pos_y][pos_x] = 'x';
	check_first(copy_map, pos_x + 1, pos_y, flag);
	check_first(copy_map, pos_x - 1, pos_y, flag);
	check_first(copy_map, pos_x, pos_y + 1, flag);
	check_first(copy_map, pos_x, pos_y - 1, flag);
}

void	start_point(char **copy_map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_h)
	{
		j = 0;
		while (j < data->map_w)
		{
			if (copy_map[i][j] == 'P')
			{
				data->start_x = j;
				data->start_y = i;
			}
			j++;
		}
		i++;
	}
}

int	check_valid_path(t_data *data)
{
	char	**copy_map;
	int		flag;

	flag = 0;
	copy_map = duplicate_map(data);
	start_point (copy_map, data);
	check_first (copy_map, data->start_x, data->start_y, &flag);
	if (check_all_collect(copy_map, data, &flag) == 1)
	{
		free_copy_map(copy_map, data->map_h);
		return (1);
	}
	free_copy_map(copy_map, data->map_h);
	return (0);
}
