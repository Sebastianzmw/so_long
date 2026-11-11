#include "so_long.h"

int	e_valid_path(t_data *data, int x, int y, char **visited)
{
	int	up;
	int	down;
	int	left;
	int	right;

	if ((y < 0 || y >= data->size_y) || (x < 0 || x >= data->size_x)
	|| data->map->map[y][x] == '1' || visited[y][x] == '1')
		return (0);
	if (data->map->map[y][x] == 'E')
		return (1);
	visited[y][x] = '1';
	up = e_valid_path(data, x, y - 1, visited);
	down = e_valid_path(data, x, y + 1, visited);
	left = e_valid_path(data, x - 1, y, visited);
	right = e_valid_path(data, x + 1, y, visited);
	if (up || down || left || right)
		return (1);
	else
		return (0);
}

int	c_valid_path(t_data *data, int x, int y, char **visited)
{
	int	up;
	int	down;
	int	left;
	int	right;

	if ((y < 0 || y >= data->size_y) || (x < 0 || x >= data->size_x)
	|| data->map->map[y][x] == '1' || visited[y][x] == '1'
	|| data->map->map[y][x] == 'E')
		return (0);
	if (data->map->map[y][x] == 'P')
		return (1);
	visited[y][x] = '1';
	up = c_valid_path(data, x, y - 1, visited);
	down = c_valid_path(data, x, y + 1, visited);
	left = c_valid_path(data, x - 1, y, visited);
	right = c_valid_path(data, x + 1, y, visited);
	if (up || down || left || right)
		return (1);
	else
		return (0);
}

static void	fill_visited(char ***visited, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		(*visited)[i] = malloc(sizeof(char) * (data->size_x + 1));
		while (data->map->map[i][j])
		{
			(*visited)[i][j] = data->map->map[i][j];
			j++;
		}
		(*visited)[i][j] = '\0';
		i++;
	}
}

void	check_collectables_path(t_data *data, int x, int y)
{
	char	**visited;

	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'C')
			{
				visited = malloc(sizeof(char *) * (data->size_y + 1));
				if (!visited)
					handle_error(data, "Error!\n allocation failure.\n", 1);
				visited[data->size_y] = 0;
				fill_visited(&visited, data);
				if (!c_valid_path(data, x, y, visited))
					handle_error(data, "Error!\n No path for collectable.\n", 1);
				free_double_p(&visited);
			}
			x++;
		}
		y++;
	}
}

void	check_path(t_data *data)
{
	char	**visited;
	int		x;
	int		y;

	x = 0;
	y = 0;
	find_py_px(data);
	visited = malloc(sizeof(char *) * (data->size_y + 1));
	if (!visited)
		handle_error(data, "Error\n! allocation failure.\n", 1);
	visited[data->size_y] = 0;
	fill_visited(&visited, data);
	if (!e_valid_path(data, data->p_x, data->p_y, visited))
	{
		free_double_p(&visited);
		handle_error(data, "Error\n! No valid path exists.\n", 1);
	}
	free_double_p(&visited);
	check_collectables_path(data, x, y);
}
