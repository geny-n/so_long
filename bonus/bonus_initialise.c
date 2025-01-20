/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_initialise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:38:15 by ngeny             #+#    #+#             */
/*   Updated: 2024/05/29 15:41:41 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	bonus_init(t_data *data)
{
	data->item.cnt_e = 0;
	data->item.cnt_c = 0;
	data->item.cnt_p = 0;
	data->item.exit = 'E';
	data->item.collect = 'C';
	data->item.player = 'P';
	data->item.wall = '1';
	data->item.space = '0';
	data->item.monster = 'M';
	data->start_x = 0;
	data->start_y = 0;
	data->map_h = bonus_map_height(data->map);
	data->map_w = bonus_map_lenght(data->map);
	data->direction = 's';
	data->cnt_move = 0;
	data->img_b.h = 55;
	data->img_b.w = 55;
	data->img_b.speed = 0;
}

void	bonus_init_image(t_data *data)
{
	bonus_init_player(data);
	bonus_init_monster(data);
	bonus_init_collect(data);
	data->img_b.exit = "./asset/majora.xpm";
	data->img_b.wall = "./asset/tree.xpm";
	data->img_b.space = "./asset/floor.xpm";
	bonus_check_image(data, data->img_b.exit);
	bonus_check_image(data, data->img_b.wall);
	bonus_check_image(data, data->img_b.space);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
}

void	bonus_display_steps(t_data *data)
{
	char	*message;
	char	*message2;

	message = ft_itoa(data->cnt_move);
	message2 = "move = ";
	if (!message)
		return ;
	mlx_set_font(data->mlx_ptr, data->mlx_win,
		"-sony-fixed-medium-r-normal--24-170-100-100-c-120-iso8859-1");
	mlx_string_put(data->mlx_ptr, data->mlx_win,
		data->img_b.w * data->map_w / 2 - 50,
		(data->img_b.h - 3) * data->map_h, 0x000000, message2);
	mlx_string_put(data->mlx_ptr, data->mlx_win,
		data->img_b.w * data->map_w / 2 + 50,
		(data->img_b.h - 3) * data->map_h, 0x000000, message);
	free(message);
}
