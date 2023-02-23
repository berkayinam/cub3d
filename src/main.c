#include "cub3d.h"

int	xbutton(t_data *data)
{
	(void)data;
	exit (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{       
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void    my_player_pixel_put(t_data *data, int x_loc, int y_loc, int color)
{
    my_mlx_pixel_put(data, x_loc, y_loc, color);
}

void    render(t_data *data)
{
        mlx_clear_window(data->mlx, data->mlx_window);
        data->img = mlx_new_image(data->mlx, data->max_long * 21, (data->last_line - data->first_line + 1) * 21);
        data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_lenght, &data->endian);
        my_mlx_map_put(data, 0x00FF0000);
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img, 0, 0);
}

void    ft_mlx_init(t_data *data)
{
        data->mlx = mlx_init();        
        data->mlx_window = mlx_new_window(data->mlx, (data->max_long - 1) * 21, (data->last_line - data->first_line + 1 ) * 21, "First");
        data->p_pixel_x = data->player_location_x * 21;
        data->p_pixel_y = data->player_location_y * 21;
        render(data);
}

int main(int ac, char **av)
{
    t_data *data;

    data = (t_data *)ft_calloc(sizeof(t_data), 1);
    if (!data)
        exit(1);
    if (ac == 2)
    {
        data = ft_calloc(sizeof(t_data),1);
        ft_all_check_and_read_map(data, av[1]);
        ft_mlx_init(data);
        mlx_hook(data->mlx_window, 2, 1L << 0, key_events, data);
        mlx_hook(data->mlx_window, 17, 0, xbutton, data);
        mlx_loop(data->mlx);
    }
    return (0);
}