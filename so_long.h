/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:47:56 by ngeny             #+#    #+#             */
/*   Updated: 2024/06/03 19:23:31 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./lib/libft/libft.h"
# include "./lib/gnl/get_next_line.h"
# include "./lib/ftprintf/ft_printf.h"
# include "./minilibx-linux/mlx.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_player
{
	void	*img_up[3];
	char	*up[3];
	void	*img_down[3];
	char	*down[3];
	void	*img_left[3];
	char	*left[3];
	void	*img_right[3];
	char	*right[3];
}	t_player;

typedef struct s_img_b
{
	void		*img_exit;
	void		*img_collect[4];
	void		*img_wall;
	void		*img_space;
	void		*img_monster[4];
	char		*exit;
	char		*collect[4];
	t_player	player;
	char		*wall;
	char		*space;
	char		*monster[4];
	int			h;
	int			w;
	int			speed;
}	t_img_b;

typedef struct s_img
{
	void	*img_exit;
	void	*img_collect;
	void	*img_player;
	void	*img_wall;
	void	*img_space;
	void	*img_monster;
	char	*exit;
	char	*collect;
	char	*player;
	char	*wall;
	char	*space;
	char	*monster;
	int		height;
	int		width;
}	t_img;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_item
{
	int		cnt_e;
	int		cnt_c;
	int		cnt_p;
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	char	monster;
}	t_item;

typedef struct s_data
{
	char		**map;
	int			map_w;
	int			map_h;
	void		*mlx_ptr;
	void		*mlx_win;
	char		direction;
	int			cnt_move;
	int			start_x;
	int			start_y;
	t_item		item;
	t_img		img;
	t_img_b		img_b;
	t_pos		pos;
}	t_data;

//utils.c
char	*error_arg(int argc, char **argv);
int		map_height(char **map);
int		map_lenght(char **map);

//initialise.c
void	init(t_data *data);
void	check_image(t_data *data, char *image);
void	init_image(t_data *data);

//image_manager.c
void	set_image(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);
int		img_place(t_data *data);
void	img_place_one(t_data *data);
void	img_place_two(t_data *data);

//keypress_manager.c
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
int		on_keypress(int keysym, t_data *data);

//check_map.c
int		map_rectagle(t_data *data);
int		verif_ecp(t_data *data);
int		check_countain(t_data *data);
int		check_side_up_down(t_data *data);
int		check_side_left_right(t_data *data);

//check_valide_path.c (flood fill)
char	**duplicate_map(t_data *data);
int		check_all_collect(char **copy_map, t_data *data, int *flag);
void	check_first(char **copy_map, int pos_x, int pos_y, int *flag);
void	start_point(char **copy_map, t_data *data);
int		check_valid_path(t_data *data);

//map.c
int		verif_empty_line(char *one_line);
char	**get_map(int fd);
char	**check_map(int fd, t_data *data);
void	play_game(t_data *data);

//free.c
void	free_get_line(char *line, char *one_line);
void	free_map(char **str);
void	free_copy_map(char **tab, int i);
int		end(t_data *data);

/**************BONUS**************/
//bonus_utils.c
char	*bonus_error_arg(int argc, char **argv);
int		bonus_map_height(char **map);
int		bonus_map_lenght(char **map);

//bonus_initialise.c
void	bonus_init(t_data *data);
void	bonus_check_image(t_data *data, char *image);

void	bonus_display_steps(t_data *data);

//bonus_init_image.c
void	bonus_init_player(t_data *data);
void	bonus_init_image(t_data *data);

//bonus_set_player.c
void	bonus_set_image_player(t_data *data);
void	animation_player(t_data *data, int x, int y);
void	animation_player_bis(t_data *data, int x, int y);

//bonus_set_collect.c
void	bonus_init_collect(t_data *data);
void	bonus_set_image_collect(t_data *data);
void	animation_collect(t_data *data, int x, int y);

//bonus_set_monster.c
void	bonus_init_monster(t_data *data);
void	bonus_set_image_monster(t_data *data);
void	animation_monster(t_data *data, int x, int y);

//bonus_image_manager.c
void	bonus_set_image(t_data *data);
void	bonus_print_img(t_data *data, void *img, int x, int y);
int		bonus_img_place(t_data *data);
void	bonus_img_place_one(t_data *data);
void	bonus_img_place_two(t_data *data);

//bonus_keypress_manager.c
void	bonus_move_up(t_data *data, int pos_x, int pos_y);
void	bonus_move_down(t_data *data, int pos_x, int pos_y);
void	bonus_move_left(t_data *data, int pos_x, int pos_y);
void	bonus_move_right(t_data *data, int pos_x, int pos_y);
int		bonus_keypress(int keysym, t_data *data);

//bonus_check_map.c
int		bonus_map_rectagle(t_data *data);
int		bonus_verif_ecp(t_data *data);
int		bonus_check_countain(t_data *data);
int		bonus_check_side_up_down(t_data *data);
int		bonus_check_side_left_right(t_data *data);

//bonus_check_valide_path.c (flood fill)
char	**bonus_duplicate_map(t_data *data);
int		bonus_check_all_collect(char **copy_map, t_data *data, int *flag);
void	bonus_check_first(char **copy_map, int pos_x, int pos_y, int *flag);
void	bonus_start_point(char **copy_map, t_data *data);
int		bonus_check_valid_path(t_data *data);

//bonus_map.c
int		bonus_verif_empty_line(char *one_line);
char	**bonus_get_map(int fd);
char	**bonus_check_map(int fd, t_data *data);
void	bonus_play_game(t_data *data);

//bonus_free.c
void	bonus_free_get_line(char *line, char *one_line);
void	bonus_free_map(char **str);
void	bonus_free_copy_map(char **tab, int i);
int		bonus_end(t_data *data);
#endif