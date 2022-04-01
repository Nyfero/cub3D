/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:23:16 by gsap              #+#    #+#             */
/*   Updated: 2022/04/01 13:23:54 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# define PI 3.1415926535
# define MV 5
# define DR 0.0174533

typedef struct s_imge
{
	void	*img;
	int		*addr;
	int		pixel;
	int		line;
	int		endian;
}	t_imge;

typedef struct s_wall
{
	t_imge			no;
	t_imge			so;
	t_imge			we;
	t_imge			ea;

	struct s_wall	*next;

}	t_wall;

typedef struct s_player
{
	float	xp;
	float	yp;
	float	dxp;
	float	dyp;
	float	ap;

}	t_player;

typedef struct s_mini_map
{
	void	*gr;
	void	*wl;
	void	*pl;
	void	*cdoor;
	void	*odoor;

	int		size_map;
}	t_mini_map;

typedef struct s_data
{
	void		*mlx;
	void		*win3d;

	t_wall		*wall;
	int			fl;
	int			cl;
	int			size;
	t_player	*pl;

	char		**map;
	int			h;
	int			l;

	t_mini_map	mmap;

	float		p2;
	float		p3;

	t_imge		screen;
	int			size_screen;

}	t_data;

typedef struct s_check
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
}	t_check;

typedef struct s_3d_dist
{
	int		r;
	t_check	vh;
	t_check	vv;
	float	ra;
	float	ca;
	float	tx;

}	t_3d_dist;

typedef struct s_3d_draw
{
	int		y;
	float	line_h;
	float	line_o;
	float	ty;
	float	ty_off;
	float	ty_step;
}	t_3d_draw;

/****************************/
/*			PARSING			*/
/****************************/

//	check_args.c
int		check_args(int argc, char **argv);
int		check_good_format(char *file);
int		error_file(int err);
int		error_player(void);
int		check_no_more(char *line, int i);

//	parsing.c
int		parsing(t_data *data, char *file);
int		init_wall(t_data *data);
int		init_map(t_data *data);
int		init_player(t_data *data);
void	convert_img_to_int(t_data *data);

//	parsing_texture.c
int		parse_wall(t_data *data, char *file);
int		parse_texture(t_data *data, char *line);
int		get_texture(t_data *data, char **tab);
int		get_color(char **line);
int		one_line(char *line);

//	parsing_map.c
int		parse_map(t_data *data, char *file);
int		get_size_map(t_data *data, char *file);
int		is_part_of_map(t_data *data, char *line);
void	get_map(t_data *data, char *line);
void	fill_map(t_data *data, char *line, int i, int j);

//	check_map.c
int		check_map_closed(t_data *data);
int		check_left(t_data *data);
int		check_right(t_data *data);
int		check_top_and_bot(t_data *data);
int		len_nbr(int nbr);

//	parsing_player.c
int		get_player_info(t_data *data);
int		place_player(t_data *data, int i, int j);

//	mini_map.c
void	short_pitw(t_data *d, void *img, int x, int y);
int		create_mini(t_data *data);
int		create_mini_bonus(t_data *data);
void	ft_mini_map_if(t_data *d, int y, int x);
void	ft_mini_map(t_data *d);

/****************************/
/*			UTILS			*/
/****************************/

//	game.c
void	ft_rotation(int nb, t_player *p);
void	ft_deplacement_hor(t_data *d, int nb, t_player *p);
void	ft_deplacement_vert(t_data *d, int nb, t_player *p);
int		ft_game_event(int key, t_data *d);
int		ft_game(t_data d);

//	print_info.c
void	print_map(t_data *data);
void	print_player(t_data *data);
void	print_texture(t_data *data);
void	print_all(t_data *data);

/****************************/
/*			END				*/
/****************************/

//	exit.c
void	exit_before_exec(t_data *data);
void	free_img(t_data *data);
int		end_cub3d(t_data *data);

/****************************/
/*			MATH			*/
/****************************/

/****************************/
/*			BONUS			*/
/****************************/

//	main_bonus.c
int		sprite(t_data *d);
void	first_sprite(t_data *d);
void	second_sprite(t_data *d);
void	destroy_sprite(t_data *data);
//t_wall	*clear(t_wall *n, t_data *d);

//	parsing_map_bonus.c
int		parsing_bonus(t_data *data, char *file);
int		parse_map_bonus(t_data *data, char *file);
int		get_size_map_bonus(t_data *data, char *file);
int		is_part_of_map_bonus(t_data *data, char *line);
void	get_map_bonus(t_data *data, char *file);

/******************************************/

//	check_deplacement.c
int		ft_check_deplacement(t_data *d, t_player *p, float dx, float dy);
int		ft_check_deplacement_2(t_data *d, t_player *p);

//	render_3d.c
void	ft_3d_render(t_data *d);
void	ft_3d_draw(t_data *d, float dist, t_3d_dist s, int *img);

//	check_horizon.c
float	ft_check_horizontal(t_data *d, t_player *pl, float ra, t_check *v);

//	check_vertical.c
float	ft_check_vertical(t_data *d, t_player *pl, float ra, t_check *v);

//	calc_utils.c
float	ft_dist(float x, float y, float x2, float y2);

//	mini_map.c
void	ft_mini_map(t_data *d);

//	door.c
void	ft_check_door(float x, float y, t_data *d);

//	utils_game.c
void	ft_utils_game_change(t_data *d, float temp_x, float temp_y);

//	render_3d_utils.c
void	ft_3d_dist_horizontal(t_data *d, float dist, t_3d_dist g);
void	ft_3d_dist_vertical(t_data *d, float dist, t_3d_dist g);
void	ft_3d_draw_init(t_data *d, t_3d_draw *g, float dist);

#endif
