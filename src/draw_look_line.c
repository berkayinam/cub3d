#include "cub3d.h"

void    draw_look_line(t_data *data)
{
    //printf("%i %i \n",data->p_pixel_x, data->p_pixel_y);
    int j = 60;
    while (j > 60)
    {
        my_mlx_pixel_put(data, data->p_pixel_x + j, data->p_pixel_y, 0xffffff);
        j--;
    }    
}