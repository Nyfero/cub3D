#include "cub3D.h"

int	check_args(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		return (error_file(1));
	else if (argc > 2)
		return (error_file(2));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		return (1);
	}
	close(fd);
	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (error_file(3));
	}
	if (check_good_format(argv[1]))
		return (error_file(4));
	return (0);
}

int	check_good_format(char *file)
{
	char	*ext;

	if (ft_strlen(file) < 5)
		return (1);
	ext = ft_substr(file, (ft_strlen(file) - 4), 5);
	if (ft_strncmp(ext, ".cub", 5))
	{
		free(ext);
		return (1);
	}
	free(ext);
	return (0);
}

int	error_file(int err)
{
	ft_putendl_fd("Error", 2);
	if (err == 1)
		ft_putendl_fd("No file submited", 2);
	else if (err == 2)
		ft_putendl_fd("Too many arguments", 2);
	else if (err == 3)
		ft_putendl_fd("argument is a directory", 2);
	else if (err == 4)
		ft_putendl_fd("Not a \"*.cub\" file", 2);
	else if (err == 5)
		ft_putendl_fd("Unvalid file", 2);
	else if (err == 6)
		ft_putendl_fd("Unvalid texture", 2);
	else if (err == 7)
		ft_putendl_fd("Map to small", 2);
	else if (err == 8)
		ft_putendl_fd("Unvalid map", 2);
	else if (err == 9)
		ft_putendl_fd("Map not closed", 2);
	else if (err == 10)
		ft_putendl_fd("To much player on the map", 2);
	else if (err == 11)
		ft_putendl_fd("Map is to big", 2);
	return (1);
}
