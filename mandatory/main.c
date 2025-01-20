/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:52:49 by ngeny             #+#    #+#             */
/*   Updated: 2025/01/02 16:40:18 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;
	char	*str;

	str = error_arg(argc, argv);
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
			if (check_map(fd, &data) == NULL)
				return (0);
			set_image(&data);
			close(fd);
		}
		else
			ft_printf("ERROR not .ber\n");
	}
	return (0);
}
