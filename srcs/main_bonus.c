/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:02:56 by gsap              #+#    #+#             */
/*   Updated: 2022/03/31 17:00:14 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv))
		return (1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (2);
	if (parsing_bonus(&data, argv[1]))
	{
		exit_before_exec(&data);
		return (3);
	}
	data.win3d = mlx_new_window(data.mlx, 720, 720, "cub3d");
	ft_game(data);
	end_cub3d(&data);
	return (0);
}
