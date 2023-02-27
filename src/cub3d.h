// north kuzey west batı east doğu south güney
#ifndef CUB3D_H
# define CUB3D_H
# define M_PI 3.141592

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_window;
	void	*img;
	char	*addr;
	int		map_size;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		width;
	char	**map;
    char	*NO;
    char	*SO;
    char	*WE;
    char	*EA;
    int		first_line;
    int		last_line;
    int		max_long;
    int		map_weight;
    int		player_location_x;
    int		player_location_y;
	int		p_pixel_x;
	int		p_pixel_y;
	int		north_degree;
	int		west_degree;
	int		east_degree;
	int		south_degree;
	char	look;
	int		look_degree;
}	t_data;

int     ft_check_cub(char *s);
void    ft_clear(t_data *data);
void    ft_check_map(t_data *data);
void    ft_check_wall(t_data *data);
void    ft_all_check_and_read_map(t_data *data, char *map);
void    ft_check_for_long(t_data *data);
void    ft_check_once_to_map(t_data *data);
void    ft_addjust2(t_data *data);
void    ft_check_file(t_data *data);
void    ft_find(t_data *data);
void    ft_I_need(t_data *data);

void	my_mlx_map_put(t_data *data, int color);
void    my_square_pixel_put(t_data *data, int x_loc, int y_loc, int color);
int		key_events(int keycode, t_data *data);
void    my_player_pixel_put(t_data *data, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    render(t_data *data);
void    player_look_degree(t_data *data, int i, int j);
int		xbutton(t_data *data);
void	draw_look_line(t_data *data);
#endif