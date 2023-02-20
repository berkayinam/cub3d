#include "cub3d.h"

int move_up(t_data *data)
{
    int y_konum = ((data->player_location_y)* 22) - 10; 
    int x_konum = ((data->player_location_x)* 22) - 10;
    printf("y konum %i / x konum %i --- pixel x %i  pixel y %i\n",y_konum,x_konum,data->p_pixel_x, data->p_pixel_y);
    if((y_konum + 20 >= data->p_pixel_y && y_konum <= data->p_pixel_y) || (x_konum + 20 >= data->p_pixel_x && x_konum <= data->p_pixel_y))
    {
        data->map[data->player_location_y - 1][data->player_location_x] = 'P';
        data->map[data->player_location_y][data->player_location_x] = '0';
        data->p_pixel_y--;
    }
    return 0;
}

int move_down(t_data *data){
    return 0;
}

int move_left(t_data *data){
    return 0;
}


int move_right(t_data *data)
{
    return(1);
}

int key_events(int keycode, t_data *data)
{
    printf("%i\n",keycode);
    if (keycode == 13)
        move_up(data);
    if (keycode == 1)
        move_down(data);
    if (keycode == 0)
        move_left(data);
    if (keycode == 2)
        move_right(data);
    render(data);
    return(1);
}