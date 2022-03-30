#include "cub3D.h"

float	ft_dist(float x, float y, float x2, float y2)
{
	return (sqrt(powf(x - x2, 2) + powf(y - y2, 2)));
}
