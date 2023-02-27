#include "cub3d.h"

void    my_square_pixel_put(t_data *data, int x_loc, int y_loc, int color)
{
  
    int x;
    int y;
    int squareWidth;

    x = 0;
    y = 0;
    squareWidth = 20;
    while (y < squareWidth)
    {
        while (x < squareWidth)
            my_mlx_pixel_put(data, x_loc + x++, y_loc + y, color);
        x = 0;
        y++;
    }
}

void	my_mlx_map_put(t_data *data, int color)
{
    int i;
    int j;
    int x_loc;
    int y_loc;

    x_loc = 0;
    y_loc = 0;
    i = data->first_line;
    j = 0;

    while (data->map[i] && i <= data->last_line)
    {
        
        while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
        {
            if (data->map[i][j] == '1')
            {
                my_square_pixel_put(data, x_loc, y_loc, color);
                x_loc +=21;
            }
            if (data->map[i][j] == '0')
                x_loc+=21;
            if(data->map[i][j] == 'N' || data->map[i][j] == 'S' ||
                data->map[i][j] == 'W' || data->map[i][j] == 'E')
            {
                x_loc+=21;
                my_player_pixel_put(data, 0xffffff);
                data->player_location_x = j;
                data->player_location_y = i;
                data->look = data->map[i][j];
            }
            j++;
        }
        i++;
        j = 0;
        y_loc += 21;
        x_loc = 0;
    }
}
