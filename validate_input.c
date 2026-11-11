#include "so_long.h"

static void	ft_check_content(t_data *data)
{
	int	k;
	int	player;
	int	exit;

	exit = 0;
	player = 0;
	data->map->collections = 0;
	k = 0;
	while (data->map->map && data->map->map[k])
	{
		exit += ft_count_c(data->map->map[k], 'E');
		player += ft_count_c(data->map->map[k], 'P');
		data->map->collections += ft_count_c(data->map->map[k], 'C');
		k++;
	}
	if (player != 1)
		handle_error(data, "Error\nThere is more than one player\n", 1);
	if (exit == 0 || exit > 1)
		handle_error(data, "Error\nonly valid map if there is one exit\n", 1);
	if (data->map->collections == 0)
		handle_error(data, "Error\nthere is nothing to collect\n", 1);
}

static void	ft_check_border(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->size_y / IMG_H))
	{
		if ((int)ft_strlen(data->map->map[y]) != data->size_x / IMG_W)
			handle_error(data, "Error\nmap has to be rectangular\n", 1);
		x = 0;
		while (x < (data->size_x / IMG_W))
		{
			if (data->map->map[y][x] != '0' && data->map->map[y][x] != '1' &&
				data->map->map[y][x] != 'C' && data->map->map[y][x] != 'P' &&
				data->map->map[y][x] != 'E')
				handle_error(data, "Error\n'0','1','C','P','E' are valid\n", 1);
			else if (((y == 0) || (x == 0)) && data->map->map[y][x] != '1')
				handle_error(data, "Error\n T or L not covered by walls\n", 1);
			else if ((y == (data->size_y / IMG_H - 1)
					|| x == (data->size_x / IMG_W - 1))
				&& data->map->map[y][x] != '1')
				handle_error(data, "Error\nB or R not covered by walls\n", 1);
			x++;
		}
		y++;
	}
}

static void	ft_input_error(t_data *data, int argc)
{
	if (argc != 2)
	{
		handle_error(data, "Error\nUsage: './so_long mappath/mapname.ber'\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	validate_input(t_data *data, char **argv, int argc)
{
	int		fd;
	int		k;
	int		bytes;
	char	buffer[2];

	ft_input_error(data, argc);
	k = 0;
	bytes = 1;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
			data->map->map[k] = ft_strjoin(data->map->map[k], buffer);
		else
			k++;
	}
	if (data->size_x / IMG_H == k)
		handle_error(data, "Error\nWrong map dimensions", 1);
	ft_check_content(data);
	ft_check_border(data);
}