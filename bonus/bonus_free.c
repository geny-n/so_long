/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:11:05 by ngeny             #+#    #+#             */
/*   Updated: 2024/05/28 23:34:17 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	bonus_free_get_line(char *line, char *one_line)
{
	free (line);
	free (one_line);
}

void	bonus_free_map(char **str)
{
	int	i;

	i = 1;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

void	bonus_free_copy_map(char **tab, int i)
{
	i--;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

void	destroy_image_animate(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_b.player.img_up[i]);
		mlx_destroy_image(data->mlx_ptr, data->img_b.player.img_down[i]);
		mlx_destroy_image(data->mlx_ptr, data->img_b.player.img_left[i]);
		mlx_destroy_image(data->mlx_ptr, data->img_b.player.img_right[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_b.img_collect[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_b.img_monster[i]);
		i++;
	}
}

int	bonus_end(t_data *data)
{
	bonus_free_map(data->map);
	if (data->map != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_b.img_exit);
		destroy_image_animate(data);
		mlx_destroy_image(data->mlx_ptr, data->img_b.img_wall);
		mlx_destroy_image(data->mlx_ptr, data->img_b.img_space);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
