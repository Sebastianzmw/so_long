#include "so_long.h"

void	check_filename(char *filename)
{
	filename = filename + (ft_strlen(filename) - 4);
	if (ft_strncmp(filename, ".ber", 4))
	{
		write(2, "Error\n Wrong file extension", 28);
		exit(1);
	}
}

void	handle_error(t_data *data, char *str, int num)
{
	if (num)
		free_double_pointer(data);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

static int	ft_render_next_frame(t_data *data)
{
	put_background(data);
	create_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	printf("              You gave up XD                    \n");
	printf("   Is the game hard for you? Try again......    \n");
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	window_size(&data, argv);
	check_filename(argv[1]);
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
		calloc_failure("Error\ncalloc failed\n");
	ft_initializer(&data, &map);
	validate_input(&data, argv, argc);
	check_path(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror("Error\nprogram initialization failed\n");
		exit(EXIT_FAILURE);
	}
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "42");
	ft_render_next_frame(&data);
	mlx_loop(data.mlx);
	perror("Error\nProgramme failed to loop\n");
	exit(EXIT_FAILURE);
}

//./so_long maps/map3.ber