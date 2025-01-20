/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:38:15 by ngeny             #+#    #+#             */
/*   Updated: 2024/05/24 12:44:52 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init(t_data *data)
{
	data->item.cnt_e = 0;
	data->item.cnt_c = 0;
	data->item.cnt_p = 0;
	data->item.exit = 'E';
	data->item.collect = 'C';
	data->item.player = 'P';
	data->item.wall = '1';
	data->item.space = '0';
	data->start_x = 0;
	data->start_y = 0;
	data->map_h = map_height(data->map);
	data->map_w = map_lenght(data->map);
	data->cnt_move = 0;
}

void	check_image(t_data *data, char *image)
{
	int	fd;

	fd = open(image, O_RDONLY, 0777);
	if (fd == -1)
	{
		ft_printf("ERROR no image\n");
		free_map(data->map);
		exit(1);
	}
	return ;
}

void	init_image(t_data *data)
{
	data->img.height = 55;
	data->img.width = 55;
	data->img.exit = "./asset/majora.xpm";
	data->img.collect = "./asset/rubis.xpm";
	data->img.player = "./asset/link.xpm";
	data->img.wall = "./asset/tree.xpm";
	data->img.space = "./asset/floor.xpm";
	check_image(data, data->img.exit);
	check_image(data, data->img.collect);
	check_image(data, data->img.player);
	check_image(data, data->img.wall);
	check_image(data, data->img.space);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
}
