/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 01:47:06 by ngeny             #+#    #+#             */
/*   Updated: 2024/06/03 15:55:29 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y - 1][pos_x] != data->item.wall)
	{
		if (data->map[pos_y - 1][pos_x] != data->item.exit)
		{
			if (data->map[pos_y - 1][pos_x] == data->item.collect)
				data->item.cnt_c--;
			data->map[pos_y - 1][pos_x] = data->item.player;
			data->map[pos_y][pos_x] = data->item.space;
			data->cnt_move++;
			ft_printf("move = %d\n", data->cnt_move);
		}
		else
		{
			if (data->item.cnt_c == 0)
			{
				ft_printf("BRAVO!! nombre de coups : %d \n", data->cnt_move);
				end(data);
			}
		}
	}
}

void	move_down(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y + 1][pos_x] != data->item.wall)
	{
		if (data->map[pos_y + 1][pos_x] != data->item.exit)
		{
			if (data->map[pos_y + 1][pos_x] == data->item.collect)
				data->item.cnt_c--;
			data->map[pos_y + 1][pos_x] = data->item.player;
			data->map[pos_y][pos_x] = data->item.space;
			data->cnt_move++;
			ft_printf("move = %d\n", data->cnt_move);
		}
		else
		{
			if (data->item.cnt_c == 0)
			{
				ft_printf("BRAVO!! nombre de coups : %d \n", data->cnt_move);
				end(data);
			}
		}
	}
}

void	move_left(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x - 1] != data->item.wall)
	{
		if (data->map[pos_y][pos_x - 1] != data->item.exit)
		{
			if (data->map[pos_y][pos_x - 1] == data->item.collect)
				data->item.cnt_c--;
			data->map[pos_y][pos_x - 1] = data->item.player;
			data->map[pos_y][pos_x] = data->item.space;
			data->cnt_move++;
			ft_printf("move = %d\n", data->cnt_move);
		}
		else
		{
			if (data->item.cnt_c == 0)
			{
				ft_printf("BRAVO!! nombre de coups : %d \n", data->cnt_move);
				end(data);
			}
		}
	}
}

void	move_right(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x + 1] != data->item.wall)
	{
		if (data->map[pos_y][pos_x + 1] != data->item.exit)
		{
			if (data->map[pos_y][pos_x + 1] == data->item.collect)
				data->item.cnt_c--;
			data->map[pos_y][pos_x + 1] = data->item.player;
			data->map[pos_y][pos_x] = data->item.space;
			data->cnt_move++;
			ft_printf("move = %d\n", data->cnt_move);
		}
		else
		{
			if (data->item.cnt_c == 0)
			{
				ft_printf("BRAVO!! nombre de coups : %d \n", data->cnt_move);
				end(data);
			}
		}
	}
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end(data);
	if (keysym == XK_w)
		move_up(data);
	if (keysym == XK_s)
		move_down(data);
	if (keysym == XK_a)
		move_left(data);
	if (keysym == XK_d)
		move_right(data);
	return (0);
}
