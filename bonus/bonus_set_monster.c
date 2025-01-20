/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_set_monster.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:17:08 by ngeny             #+#    #+#             */
/*   Updated: 2024/05/28 23:38:06 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	bonus_init_monster(t_data *data)
{
	int	i;

	i = 0;
	data->img_b.monster[0] = "./asset/chicken_move/chicken_1.xpm";
	data->img_b.monster[1] = "./asset/chicken_move/chicken_2.xpm";
	data->img_b.monster[2] = "./asset/chicken_move/chicken_1.xpm";
	data->img_b.monster[3] = "./asset/chicken_move/chicken_2.xpm";
	while (i < 4)
	{
		bonus_check_image(data, data->img_b.monster[i]);
		i++;
	}
}

void	bonus_set_image_monster(t_data *data)
{
	data->img_b.img_monster[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.monster[0], &(data->img_b.w), &(data->img_b.h));
	data->img_b.img_monster[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.monster[1], &(data->img_b.w), &(data->img_b.h));
	data->img_b.img_monster[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.monster[2], &(data->img_b.w), &(data->img_b.h));
	data->img_b.img_monster[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.monster[3], &(data->img_b.w), &(data->img_b.h));
}

void	animation_monster(t_data *data, int x, int y)
{
	if (data->img_b.speed == 0)
		bonus_print_img(data, data->img_b.img_monster[0], x, y);
	else if (data->img_b.speed == 500)
		bonus_print_img(data, data->img_b.img_monster[1], x, y);
	else if (data->img_b.speed == 1000)
		bonus_print_img(data, data->img_b.img_monster[2], x, y);
	else if (data->img_b.speed == 1000)
		bonus_print_img(data, data->img_b.img_monster[3], x, y);
}
