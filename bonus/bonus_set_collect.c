/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_set_collect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:17:08 by ngeny             #+#    #+#             */
/*   Updated: 2024/05/28 21:46:03 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	bonus_init_collect(t_data *data)
{
	int	i;

	i = 0;
	data->img_b.collect[0] = "./asset/rubi_move/rubi_1.xpm";
	data->img_b.collect[1] = "./asset/rubi_move/rubi_2.xpm";
	data->img_b.collect[2] = "./asset/rubi_move/rubi_3.xpm";
	data->img_b.collect[3] = "./asset/rubi_move/rubi_4.xpm";
	while (i < 4)
	{
		bonus_check_image(data, data->img_b.collect[i]);
		i++;
	}
}

void	bonus_set_image_collect(t_data *data)
{
	data->img_b.img_collect[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.collect[0], &(data->img_b.w), &(data->img_b.h));
	data->img_b.img_collect[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.collect[1], &(data->img_b.w), &(data->img_b.h));
	data->img_b.img_collect[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.collect[2], &(data->img_b.w), &(data->img_b.h));
	data->img_b.img_collect[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.collect[3], &(data->img_b.w), &(data->img_b.h));
}

void	animation_collect(t_data *data, int x, int y)
{
	if (data->img_b.speed == 0)
		bonus_print_img(data, data->img_b.img_collect[0], x, y);
	else if (data->img_b.speed == 500)
		bonus_print_img(data, data->img_b.img_collect[1], x, y);
	else if (data->img_b.speed == 1000)
		bonus_print_img(data, data->img_b.img_collect[2], x, y);
	else if (data->img_b.speed == 1000)
		bonus_print_img(data, data->img_b.img_collect[3], x, y);
}
