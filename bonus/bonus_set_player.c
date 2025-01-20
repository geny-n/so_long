/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_set_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:17:08 by ngeny             #+#    #+#             */
/*   Updated: 2024/06/03 19:02:33 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	bonus_init_player(t_data *data)
{
	int	i;

	i = 0;
	data->img_b.player.up[0] = "./asset/link_move/up/up_link1.xpm";
	data->img_b.player.up[1] = "./asset/link_move/up/up_link2.xpm";
	data->img_b.player.up[2] = "./asset/link_move/up/up_link3.xpm";
	data->img_b.player.down[0] = "./asset/link_move/down/down_link1.xpm";
	data->img_b.player.down[1] = "./asset/link_move/down/down_link2.xpm";
	data->img_b.player.down[2] = "./asset/link_move/down/down_link3.xpm";
	data->img_b.player.left[0] = "./asset/link_move/left/left_link1.xpm";
	data->img_b.player.left[1] = "./asset/link_move/left/left_link2.xpm";
	data->img_b.player.left[2] = "./asset/link_move/left/left_link3.xpm";
	data->img_b.player.right[0] = "./asset/link_move/right/right_link1.xpm";
	data->img_b.player.right[1] = "./asset/link_move/right/right_link2.xpm";
	data->img_b.player.right[2] = "./asset/link_move/right/right_link3.xpm";
	while (i < 3)
	{
		bonus_check_image(data, data->img_b.player.down[i]);
		bonus_check_image(data, data->img_b.player.up[i]);
		bonus_check_image(data, data->img_b.player.left[i]);
		bonus_check_image(data, data->img_b.player.right[i]);
		i++;
	}
}

void	bonus_set_image_player(t_data *data)
{
	data->img_b.player.img_up[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.player.up[0], &(data->img_b.w), &(data->img_b.h));
	data->img_b.player.img_up[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.player.up[1], &(data->img_b.h), &(data->img_b.h));
	data->img_b.player.img_up[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.player.up[2], &(data->img_b.h), &(data->img_b.h));
	data->img_b.player.img_down[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.player.down[0], &(data->img_b.h), &(data->img_b.h));
	data->img_b.player.img_down[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.player.down[1], &(data->img_b.h), &(data->img_b.h));
	data->img_b.player.img_down[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.player.down[2], &(data->img_b.h), &(data->img_b.h));
	data->img_b.player.img_left[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.player.left[0], &(data->img_b.h), &(data->img_b.h));
	data->img_b.player.img_left[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.player.left[1], &(data->img_b.h), &(data->img_b.h));
	data->img_b.player.img_left[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.player.left[2], &(data->img_b.h), &(data->img_b.h));
	data->img_b.player.img_right[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.player.right[0], &(data->img_b.h), &(data->img_b.h));
	data->img_b.player.img_right[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.player.right[1], &(data->img_b.h), &(data->img_b.h));
	data->img_b.player.img_right[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img_b.player.right[2], &(data->img_b.h), &(data->img_b.h));
}

void	animation_player(t_data *data, int x, int y)
{
	if (data->direction == 's')
	{
		if (data->img_b.speed == 0)
			bonus_print_img(data, data->img_b.player.img_down[0], x, y);
		else if (data->img_b.speed == 500)
			bonus_print_img(data, data->img_b.player.img_down[1], x, y);
		else if (data->img_b.speed == 1000)
			bonus_print_img(data, data->img_b.player.img_down[2], x, y);
	}
	if (data->direction == 'w')
	{
		if (data->img_b.speed == 0)
			bonus_print_img(data, data->img_b.player.img_up[0], x, y);
		else if (data->img_b.speed == 500)
			bonus_print_img(data, data->img_b.player.img_up[1], x, y);
		else if (data->img_b.speed == 1000)
			bonus_print_img(data, data->img_b.player.img_up[2], x, y);
	}
	animation_player_bis(data, x, y);
}

void	animation_player_bis(t_data *data, int x, int y)
{
	if (data->direction == 'a')
	{
		if (data->img_b.speed == 0)
			bonus_print_img(data, data->img_b.player.img_left[0], x, y);
		else if (data->img_b.speed == 500)
			bonus_print_img(data, data->img_b.player.img_left[1], x, y);
		else if (data->img_b.speed == 1000)
			bonus_print_img(data, data->img_b.player.img_left[2], x, y);
	}
	if (data->direction == 'd')
	{
		if (data->img_b.speed == 0)
			bonus_print_img(data, data->img_b.player.img_right[0], x, y);
		else if (data->img_b.speed == 500)
			bonus_print_img(data, data->img_b.player.img_right[1], x, y);
		else if (data->img_b.speed == 1000)
			bonus_print_img(data, data->img_b.player.img_right[2], x, y);
	}
}
