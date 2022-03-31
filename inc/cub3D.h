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
# define P2 PI / 2
# define P3 3 * PI / 2
# define MV 5
# define DR 0.0174533

typedef struct	s_imge
{
	void	*img;
	int		*addr;
	int		pixel;
	int		line;
	int		endian;
}	t_imge;

typedef struct	s_wall
{
	t_imge			no;
	t_imge			so;
	t_imge			we;
	t_imge			ea;

	int				fl;
	int				cl;

	struct s_wall	*next;

}	t_wall;

typedef struct	s_player
{
	float	xp;
	float	yp;
	float	dxp;
	float	dyp;
	float	ap;

}	t_player;

typedef struct	s_mini_map
{
	void	*gr;
	void	*wl;
	void	*pl;
	void	*cdoor;
	void	*odoor;

	int		size_map;
}	t_mini_map;

typedef struct	s_data
{
	void		*mlx;
	void		*win3d;

	t_wall		wall;
	int			size;
	t_player	*pl;
	
	char		**map;
	int			h;
	int			l;

	t_mini_map	mmap;
	
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

int		mouse_hook(int mouse, t_data *data);
void	init_mouse(t_data *data);

/****************************/
/*			PARSING			*/
/****************************/

//	check_args.c
int		check_args(int argc, char **argv);
int		check_good_format(char *file);
int		error_file(int err);

//	parsing.c
int		parsing(t_data *data, char *file);
void	init_wall(t_data *data);
int		init_map(t_data *data);
int		init_player(t_data *data);
void	convert_img_to_int(t_data *data);

//	parsing_texture.c
int		parse_wall(t_data *data, char *file);
int		parse_texture(t_data *data, char *line);
int		get_texture(t_data *data, char ** tab);
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
int		create_mini_map(t_data *data);
int		create_mini_map_bonus(t_data *data);

/****************************/
/*			UTILS			*/
/****************************/

//	print_info.c
void	print_map(t_data *data);
void	print_player(t_data *data);
void	print_texture(t_data *data);

/****************************/
/*			END				*/
/****************************/

//	exit.c
void 	exit_before_exec(t_data *data);
void	free_img(t_data *data);
void	end_cub3d(t_data *data);

/****************************/
/*			MATH			*/
/****************************/

/****************************/
/*			BONUS			*/
/****************************/

//	parsing_map_bonus.c
int		parsing_bonus(t_data *data, char *file);
int		parse_map_bonus(t_data *data, char *file);
int		get_size_map_bonus(t_data *data, char *file);
int		is_part_of_map_bonus(t_data *data, char *line);
void	get_map_bonus(t_data *data, char *file);

/******************************************/


//	texture.c
void	ft_affichage_map(t_data *d);
void	ft_put_img(t_data *d, void *image, int x, int y);
void	ft_creation_img(t_data *d);

//	game.c
int	ft_game(t_data d);
void	ft_rotation(int nb, t_player *p);

//	exit_jgour.c
int	cub3d_exit(t_data *d);

//	check_deplacement.c
int	ft_check_deplacement(t_data *d, t_player *p, float dx, float dy);
int	ft_check_deplacement_2(t_data *d, t_player *p);

//	render_3d.c
void	ft_3d_render(t_data *d);

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

#endif
