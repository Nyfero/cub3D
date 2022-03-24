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
	t_player	pl;
	char		**map;

}	t_data;

#endif
