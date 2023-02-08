

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*path;
	int		img_height;
	int		img_width;
	int		x;
	int		y;
	char	**map;
}				t_data;

void move_character(t_data *data, int d);

#endif
