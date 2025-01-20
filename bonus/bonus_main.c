/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:15:23 by ngeny             #+#    #+#             */
/*   Updated: 2024/05/16 00:07:12 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;
	char	*str;

	str = bonus_error_arg(argc, argv);
	if (str != NULL)
	{
		if (ft_strcmp(str, ".ber") == 0)
		{
			fd = open(argv[1], O_RDONLY, 0777);
			if (fd == -1)
			{
				ft_printf("file not exist\n");
				return (0);
			}
			if (bonus_check_map(fd, &data) == NULL)
				return (0);
			bonus_set_image(&data);
			close(fd);
		}
		else
			ft_printf("ERROR not .ber\n");
	}
	return (0);
}
