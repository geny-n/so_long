/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:39:11 by ngeny             #+#    #+#             */
/*   Updated: 2024/06/03 18:46:12 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	bonus_map_rectagle(t_data *data)
{
	int	first_len;
	int	len;
	int	i;

	first_len = 0;
	len = 0;
	i = 1;
	first_len = ft_strlen(data->map[0]);
	while (i < data->map_h)
	{
		len = ft_strlen(data->map[i]);
		if (len != first_len)
		{
			ft_printf("ERROR not rectangle\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	bonus_verif_ecp(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				data->item.cnt_e++;
			else if (data->map[i][j] == 'C')
				data->item.cnt_c++;
			else if (data->map[i][j] == 'P')
				data->item.cnt_p++;
			j++;
		}
		i++;
	}
	if (data->item.cnt_e != 1 || data->item.cnt_c < 1 || data->item.cnt_p != 1)
	{
		ft_printf("ERROR bad number of E C P\n");
		return (0);
	}
	return (1);
}

int	bonus_check_countain(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0'
				&& data->map[i][j] != '1'
				&& data->map[i][j] != 'E'
				&& data->map[i][j] != 'C'
				&& data->map[i][j] != 'P'
				&& data->map[i][j] != 'M')
			{
				ft_printf("ERROR wrong values\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	bonus_check_side_up_down(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1')
		{
			ft_printf("ERROR wall haut\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (data->map[data->map_h - 1][i])
	{
		if (data->map[data->map_h - 1][i] != '1')
		{
			ft_printf("ERROR wall bas\n");
			return (0);
		}
		i++;
	}
	if (bonus_check_side_left_right(data) == 0)
		return (0);
	return (1);
}

int	bonus_check_side_left_right(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->map_h - 1)
	{
		if (data->map[i][0] != '1')
		{
			ft_printf("ERROR wall gauche\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i <= data->map_h - 1)
	{
		if (data->map[i][data->map_w - 1] != '1')
		{
			ft_printf("ERROR wall droite\n");
			return (0);
		}
		i++;
	}
	return (1);
}
