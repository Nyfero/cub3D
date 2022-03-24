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
	int		xp;
	int		yp;
	float	r;

}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;

	t_wall		wall;
	t_player	*pl;
	char		**map;

}	t_data;

//	check_args.c
int		check_args(int argc, char **argv);
int		check_good_format(char *file);
int		error_file(int err);

//	parsing.c
int		parsing(t_data *data, char *file);
void	init_wall(t_data *data);

//	parsing_texture.c
int		parse_wall(t_data *data, char *file);
int		parse_texture(t_data *data, char *line);
int		get_texture(t_data *data, char ** tab);
int		get_color(char *line);

//	exit.c
void	free_img(t_data *data);

#endif
