/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:11:05 by ngeny             #+#    #+#             */
/*   Updated: 2024/05/18 14:42:23 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_get_line(char *line, char *one_line)
{
	free (line);
	free (one_line);
}

void	free_map(char **str)
{
	int	i;

	i = 1;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(*(str + i));
		i--;
	}
	free(str);
}

void	free_copy_map(char **tab, int i)
{
	i--;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

int	end(t_data *data)
{
	if (data->map != NULL)
	{
		free_map(data->map);
		mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
		mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
		mlx_destroy_image(data->mlx_ptr, data->img.img_player);
		mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
		mlx_destroy_image(data->mlx_ptr, data->img.img_space);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
