/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_keypress_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 01:47:06 by ngeny             #+#    #+#             */
/*   Updated: 2024/06/03 15:57:52 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	bonus_move_up(t_data *data, int pos_x, int pos_y)
{
	data->direction = 'w';
	if (data->map[pos_y - 1][pos_x] != data->item.wall)
	{
		if (data->map[pos_y - 1][pos_x] != data->item.exit)
		{
			if (data->map[pos_y - 1][pos_x] == data->item.collect)
				data->item.cnt_c--;
			else if (data->map[pos_y - 1][pos_x] == data->item.monster)
			{
				ft_printf("you are dead\n");
				bonus_end(data);
			}
			data->map[pos_y - 1][pos_x] = data->item.player;
			data->map[pos_y][pos_x] = data->item.space;
			data->cnt_move++;
		}
		else
		{
			if (data->item.cnt_c == 0)
			{
				ft_printf("BRAVO!! nombre de coups : %d \n", data->cnt_move);
				bonus_end(data);
			}
		}
	}
}

void	bonus_move_down(t_data *data, int pos_x, int pos_y)
{
	data->direction = 's';
	if (data->map[pos_y + 1][pos_x] != data->item.wall)
	{
		if (data->map[pos_y + 1][pos_x] != data->item.exit)
		{
			if (data->map[pos_y + 1][pos_x] == data->item.collect)
				data->item.cnt_c--;
			else if (data->map[pos_y + 1][pos_x] == data->item.monster)
			{
				ft_printf("you are dead\n");
				bonus_end(data);
			}
			data->map[pos_y + 1][pos_x] = data->item.player;
			data->map[pos_y][pos_x] = data->item.space;
			data->cnt_move++;
		}
		else
		{
			if (data->item.cnt_c == 0)
			{
				ft_printf("BRAVO!! nombre de coups : %d \n", data->cnt_move);
				bonus_end(data);
			}
		}
	}
}

void	bonus_move_left(t_data *data, int pos_x, int pos_y)
{
	data->direction = 'a';
	if (data->map[pos_y][pos_x - 1] != data->item.wall)
	{
		if (data->map[pos_y][pos_x - 1] != data->item.exit)
		{
			if (data->map[pos_y][pos_x - 1] == data->item.collect)
				data->item.cnt_c--;
			else if (data->map[pos_y][pos_x - 1] == data->item.monster)
			{
				ft_printf("you are dead\n");
				bonus_end(data);
			}
			data->map[pos_y][pos_x - 1] = data->item.player;
			data->map[pos_y][pos_x] = data->item.space;
			data->cnt_move++;
		}
		else
		{
			if (data->item.cnt_c == 0)
			{
				ft_printf("BRAVO!! nombre de coups : %d \n", data->cnt_move);
				bonus_end(data);
			}
		}
	}
}

void	bonus_move_right(t_data *data, int pos_x, int pos_y)
{
	data->direction = 'd';
	if (data->map[pos_y][pos_x + 1] != data->item.wall)
	{
		if (data->map[pos_y][pos_x + 1] != data->item.exit)
		{
			if (data->map[pos_y][pos_x + 1] == data->item.collect)
				data->item.cnt_c--;
			else if (data->map[pos_y][pos_x + 1] == data->item.monster)
			{
				ft_printf("you are dead\n");
				bonus_end(data);
			}
			data->map[pos_y][pos_x + 1] = data->item.player;
			data->map[pos_y][pos_x] = data->item.space;
			data->cnt_move++;
		}
		else
		{
			if (data->item.cnt_c == 0)
			{
				ft_printf("BRAVO!! nombre de coups : %d \n", data->cnt_move);
				bonus_end(data);
			}
		}
	}
}

int	bonus_keypress(int keysym, t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img_b.h;
	pos_y = data->pos.y / data->img_b.w;
	if (keysym == XK_Escape)
		bonus_end(data);
	if (keysym == XK_w)
		bonus_move_up(data, pos_x, pos_y);
	if (keysym == XK_s)
		bonus_move_down(data, pos_x, pos_y);
	if (keysym == XK_a)
		bonus_move_left(data, pos_x, pos_y);
	if (keysym == XK_d)
		bonus_move_right(data, pos_x, pos_y);
	return (0);
}
