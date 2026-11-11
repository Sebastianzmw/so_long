#include "so_long.h"

void	winner(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	printf("                 You won!                     \n");
	printf("     Is %d moves the best you can do?        \n", data->counter);
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}
