/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:38:58 by ngeny             #+#    #+#             */
/*   Updated: 2024/05/15 23:45:32 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_image(t_data *data)
{
	init_image(data);
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_space = mlx_xpm_file_to_image(data->mlx_ptr, data->img.space,
			&(data->img.width), &(data->img.height));
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			(data->map_w * data->img.width),
			(data->map_h * data->img.height), "So_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &img_place, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &on_keypress, data);
	mlx_hook(data->mlx_win, 17, 0, &end, data);
	mlx_loop(data->mlx_ptr);
	end(data);
}

int	img_place(t_data *data)
{
	img_place_one(data);
	img_place_two(data);
	return (0);
}

void	img_place_one(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->item.exit)
				print_img(data, data->img.img_exit, x, y);
			if (data->map[y][x] == data->item.collect)
				print_img(data, data->img.img_collect, x, y);
			x++;
		}
		y++;
	}
}

void	img_place_two(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->item.player)
			{
				data->pos.x = x * data->img.width;
				data->pos.y = y * data->img.height;
				print_img(data, data->img.img_player, x, y);
			}
			if (data->map[y][x] == data->item.wall)
				print_img(data, data->img.img_wall, x, y);
			if (data->map[y][x] == data->item.space)
				print_img(data, data->img.img_space, x, y);
			x++;
		}
		y++;
	}
}

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.width * x, data->img.height * y);
}
