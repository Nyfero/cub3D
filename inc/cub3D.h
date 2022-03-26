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

# define PI 3.1415926535
# define P2 PI / 2
# define P3 3 * PI / 2
# define MV 5

typedef struct s_wall
{
	void			*no;
	void			*so;
	void			*we;
	void			*ea;
	int				size;

	int				fl;
	int				cl;

	struct s_wall	*next;

}	t_wall;

typedef struct s_player
{
	float		xp;
	float		yp;
	float	dxp;
	float	dyp;
	float	ap;

}	t_player;

typedef struct s_map
{
	char	**m;
	int		x;
	int		y;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;

	t_wall		wall;
	t_player	*pl;
	t_map		map;

	int			size;
	int			h;
	int			l;

	void		*s;
	void		*w;
	void		*p;
	void		*win3d;

}	t_data;

<<<<<<< HEAD
//	print_info.c
void	print_map(t_data *data);
void	print_player(t_data *data);

=======
typedef struct s_check
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
}	t_check;

//	texture.c
void	ft_affichage_map(t_data *d);
void	ft_put_img(t_data *d, void *image, int x, int y);
void	ft_creation_img(t_data *d);

//	game.c
int	ft_game(t_data d);

//	exit_jgour.c
int	cub3d_exit(t_data *d);

//	check_deplacement.c
int	ft_check_deplacement(t_data *d, t_player *p, float dx, float dy);
int	ft_check_deplacement_2(t_data *d, t_player *p);
>>>>>>> 7c64ef4dae6220ab70cf30ea51fc6bf4b2a50c2d
//	check_args.c
int		check_args(int argc, char **argv);
int		check_good_format(char *file);
int		error_file(int err);

//	check_map.c
int		check_map_closed(t_data *data);
int		check_left(t_data *data);
int		check_right(t_data *data);
int		check_top_and_bot(t_data *data);

//	parsing.c
int		parsing(t_data *data, char *file);
void	init_wall(t_data *data);
int		init_map(t_data *data);
int		init_player(t_data *data);

//	parsing_texture.c
int		parse_wall(t_data *data, char *file);
int		parse_texture(t_data *data, char *line);
int		get_texture(t_data *data, char ** tab);
int		get_color(char *line);

//	parsing_map.c
int		parse_map(t_data *data, char *file);
int		get_size_map(t_data *data, char *file);
int		is_part_of_map(t_data *data, char *line);
void	get_map(t_data *data, char *line);
void	fill_map(t_data *data, char *line, int i, int j);

//	parsing_player.c
int		get_player_info(t_data *data);
int		place_player(t_data *data, int i, int j);

//	exit.c
void 	exit_before_exec(t_data *data);
void	free_img(t_data *data);
<<<<<<< HEAD



/******************************************/


//	texture.c
void	ft_affichage_map(t_data *d);
void	ft_put_img(t_data *d, void *image, int x, int y);
void	ft_creation_img(t_data *d);

//	game.c
int	ft_game(t_data d);

//	exit_jgour.c
int	cub3d_exit(t_data *d);
=======
>>>>>>> 7c64ef4dae6220ab70cf30ea51fc6bf4b2a50c2d

//	render_3d.c
void	ft_3d_render(t_data *d);

<<<<<<< HEAD
//	check_deplacement.c
int	ft_check_deplacement(t_data *d, t_player *p, float dx, float dy);
int	ft_check_deplacement_2(t_data *d, t_player *p);
=======
//	check_horizon.c
float	ft_check_horizontal(t_data *d, t_player *pl);

//	check_vertical.c
float	ft_check_vertical(t_data *d, t_player *pl);
//	calc_utils.c
float	ft_dist(float x, float y, float x2, float y2);
>>>>>>> 7c64ef4dae6220ab70cf30ea51fc6bf4b2a50c2d
#endif
