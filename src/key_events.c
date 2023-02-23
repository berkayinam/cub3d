#include "cub3d.h"

int move_up(t_data *data, int loc_y)
{
    if(loc_y * 21 < data->p_pixel_y)
        data->p_pixel_y--;
    if (!(loc_y * 21 < data->p_pixel_y) && data->map[data->player_location_y - 1][data->player_location_x] != '1')
    {
        data->map[data->player_location_y - 1][data->player_location_x] = 'N';
        data->map[data->player_location_y][data->player_location_x] = '0';
        data->player_location_y--;
    }
    return 0;
}

int move_down(t_data *data, int loc_y)
{
    if(loc_y * 21 + 20 > data->p_pixel_y) 
        data->p_pixel_y++;
    if (!(loc_y * 21 > 20 + data->p_pixel_y) && data->map[data->player_location_y + 1][data->player_location_x] != '1')
    {
        data->map[data->player_location_y + 1][data->player_location_x] = 'N';
        data->map[data->player_location_y][data->player_location_x] = '0';
        data->player_location_y++;
    }
    return 0;
}

int move_left(t_data *data, int loc_y)
{
    if(data->player_location_x * 21 < data->p_pixel_x) 
        data->p_pixel_x--;
    if (!(data->player_location_x * 21 < data->p_pixel_x) && data->map[data->player_location_y][data->player_location_x - 1] != '1')
    {
        data->map[data->player_location_y][data->player_location_x - 1] = 'N';
        data->map[data->player_location_y][data->player_location_x] = '0';
        data->player_location_x--;
    }
    return 0;
}


int move_right(t_data *data, int loc_y)
{
    if(data->player_location_x * 21 + 20 > data->p_pixel_x)
        data->p_pixel_x++;
    if (!(data->player_location_x * 21 + 20 > data->p_pixel_x) && data->map[data->player_location_y][data->player_location_x + 1] != '1')
    {
        data->map[data->player_location_y][data->player_location_x + 1] = 'N';
        data->map[data->player_location_y][data->player_location_x] = '0';
        data->player_location_x++;
    }
    return 0;
}

void    see_map(t_data *data)
{
    int i = data->first_line;
    int j = data->last_line;
    while (i <= j)
        printf("%s",data->map[i++]);
}

void    rotate_left(t_data *data)
{
 printf("%s\n","sağ");
}

void    rotate_right(t_data *data)
{
 printf("%s\n","sol");
}

int key_events(int keycode, t_data *data)
{
    int loc_y = 0;
    loc_y = data->player_location_y - data->first_line;

   
    if (keycode == 13)
        move_up(data,loc_y);
    if (keycode == 1)
        move_down(data, loc_y);
    if (keycode == 0)
        move_left(data, loc_y);
    if (keycode == 2)
        move_right(data, loc_y);
    if (keycode == 123)
        rotate_right(data);
    if (keycode == 124)
        rotate_left(data);
    if (keycode == 49)
        see_map(data);
    render(data);
    return(1);
}