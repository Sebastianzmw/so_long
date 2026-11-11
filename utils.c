#include "so_long.h"

void	calloc_failure(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	find_py_px(t_data *data)
{
	int	x;
	int	y;
	
	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
			}
			x++;
		}
		y++;
	}
}

void	free_double_p(char ***str)
{
	int	k;

	k = 0;
	while ((*str)[k])
		k++;
	while (k > 0)
	{
		k--;
		free((*str)[k]);
	}
	free((*str));
}
