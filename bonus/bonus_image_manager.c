/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_image_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:38:58 by ngeny             #+#    #+#             */
/*   Updated: 2024/06/03 15:58:15 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	bonus_set_image(t_data *data)
{
	bonus_init_image(data);
	data->img_b.img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.exit, &(data->img_b.w), &(data->img_b.h));
	bonus_set_image_player(data);
	bonus_set_image_monster(data);
	bonus_set_image_collect(data);
	data->img_b.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.wall, &(data->img_b.w), &(data->img_b.h));
	data->img_b.img_space = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.space, &(data->img_b.w), &(data->img_b.h));
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			(data->map_w * data->img_b.w),
			(data->map_h * data->img_b.h), "So_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &bonus_img_place, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &bonus_keypress, data);
	mlx_hook(data->mlx_win, 17, 0, &bonus_end, data);
	mlx_loop(data->mlx_ptr);
	bonus_end(data);
}

int	bonus_img_place(t_data *data)
{
	bonus_img_place_one(data);
	bonus_img_place_two(data);
	data->img_b.speed += 5;
	if (data->img_b.speed == 1000)
		data->img_b.speed = 0;
	return (0);
}

void	bonus_img_place_one(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->item.monster)
				animation_monster(data, x, y);
			if (data->map[y][x] == data->item.collect)
				animation_collect(data, x, y);
			if (data->map[y][x] == data->item.player)
			{
				data->pos.x = x * data->img_b.w;
				data->pos.y = y * data->img_b.h;
				animation_player(data, x, y);
			}
			x++;
		}
		y++;
	}
}

void	bonus_img_place_two(t_data *data)
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
				bonus_print_img(data, data->img_b.img_exit, x, y);
			if (data->map[y][x] == data->item.wall)
				bonus_print_img(data, data->img_b.img_wall, x, y);
			if (data->map[y][x] == data->item.space)
				bonus_print_img(data, data->img_b.img_space, x, y);
			x++;
		}
		y++;
	}
}

void	bonus_print_img(t_data *data, void *img, int x, int y)
{
	bonus_display_steps(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img_b.w * x, data->img_b.h * y);
}
