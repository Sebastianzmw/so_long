#include "so_long.h"

void	free_double_pointer(t_data *data)
{
	int	k;

	if (data == NULL || data->map == NULL ||
		data->map->map == NULL)
		return ;
	k = 0;
	while (data->map->map[k])
		k++;
	while (k >= 0)
	{
		free(data->map->map[k]);
		k--;
	}
	free(data->map->map);
	if (data->img)
		free(data->img);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W || keycode == UARROW)
		ft_move(data, 'y', UP);
	else if (keycode == A || keycode == LARROW)
		ft_move(data, 'x', LEFT);
	else if (keycode == S || keycode == DARROW)
		ft_move(data, 'y', DOWN);
	else if (keycode == D || keycode == RARROW)
		ft_move(data, 'x', RIGHT);
	if (data->map->map[data->p_y][data->p_x] == 'E')
		winner(data);
	return (0);
}
