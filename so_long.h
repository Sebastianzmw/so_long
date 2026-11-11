#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define IMG_W 32
# define IMG_H 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UARROW 126
# define LARROW 123
# define DARROW 125
# define RARROW 124
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_img
{
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*background;
}	t_img;

typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		collections;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}	t_data;

void	window_size(t_data *data, char **argv);
void	check_filename(char *filename);
void	calloc_failure(char *str);
void	handle_error(t_data *data, char *str, int num);
void	free_double_pointer(t_data *data);
void	ft_initializer(t_data *data, t_map *map);
void	validate_input(t_data *data, char **argv, int argc);
void	find_py_px(t_data *data);
int		c_valid_path(t_data *data, int x, int y, char **visited);
int		e_valid_path(t_data *data, int x, int y, char **visited);
void	free_double_p(char ***str);
void	check_collectables_path(t_data *data, int x, int y);
void	check_path(t_data *data);
void	put_background(t_data *data);
void	put_object(t_data *data, char *relative_path);
void	create_map(t_data *data);
void	put_player(t_data *data);
int		ft_key_hook(int keycode, t_data *data);
int		ft_exit(t_data *data);
void	ft_move(t_data *data, char pos, int dir);
void	winner(t_data *data);
void	ft_putstr_fd(char *s, int fd);

#endif