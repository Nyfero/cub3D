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
# define MV 5

typedef struct s_wall
{
	void			*no;
	void			*so;
	void			*we;
	void			*ea;

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

typedef struct s_data
{
	void		*mlx;
	void		*win;

	t_wall		wall;
	t_player	*pl;
	char		**map;

	int			size;
	int			h;
	int			l;

	void		*s;
	void		*w;
	void		*p;

}	t_data;

//	texture.c
void	ft_affichage_map(t_data *d);
void	ft_put_img(t_data *d, void *image, int x, int y);
void	ft_creation_img(t_data *d);

//	game.c
int	ft_game(t_data d);

//	exit_jgour.c
int	cub3d_exit(t_data *d);

//	print_2d.c
void	ft_aff_2d(t_data d);

//	check_deplacement.c
int	ft_check_deplacement(t_data *d, t_player *p, float dx, float dy);
int	ft_check_deplacement_2(t_data *d, t_player *p);

#endif
