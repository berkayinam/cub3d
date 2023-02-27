#include "cub3d.h"

int move_up(t_data *data, int loc_y)
{
       data->p_pixel_x += (cos(M_PI / 180 * data->look_degree));
    data->p_pixel_y += (sin(M_PI / 180 * data->look_degree));
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
    data->p_pixel_x += (cos(M_PI / 180 * data->look_degree));
    data->p_pixel_y += (sin(M_PI / 180 * data->look_degree));
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
        data->p_pixel_x += (cos(M_PI / 180 * data->look_degree));
    data->p_pixel_y += (sin(M_PI / 180 * data->look_degree));
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

void    look_control(t_data *data)
{
    if (data->look_degree == 0)
    {
        data->look_degree = data->map[data->player_location_y][data->player_location_x];
        data->look_degree = 90;
    }
}

void    rotate_left(t_data *data)
{
    if (data->look_degree <= 0)
        data->look_degree = 359 - data->look_degree;
    else
        data->look_degree--;
    if (data->map[data->player_location_y][data->player_location_x] == 'N' && data->look_degree == 359)
        data->map[data->player_location_y][data->player_location_x] = 'W';
    if (data->map[data->player_location_y][data->player_location_x] == 'W' && data->look_degree == 270)
        data->map[data->player_location_y][data->player_location_x] = 'S';
    if (data->map[data->player_location_y][data->player_location_x] == 'S' && data->look_degree == 180)
        data->map[data->player_location_y][data->player_location_x] = 'E';
    if (data->map[data->player_location_y][data->player_location_x] == 'E' && data->look_degree == 90)
        data->map[data->player_location_y][data->player_location_x] = 'N';
}

void    rotate_right(t_data *data)
{
    if (data->look_degree == 359)
        data->look_degree = 0;
    else
        data->look_degree++;
    if (data->map[data->player_location_y][data->player_location_x] == 'N' && data->look_degree == 90)
        data->map[data->player_location_y][data->player_location_x] = 'E';
    if (data->map[data->player_location_y][data->player_location_x] == 'E' && data->look_degree == 180)
        data->map[data->player_location_y][data->player_location_x] = 'S';
    if (data->map[data->player_location_y][data->player_location_x] == 'S' && data->look_degree == 270)
        data->map[data->player_location_y][data->player_location_x] = 'W';
    if (data->map[data->player_location_y][data->player_location_x] == 'W' && data->look_degree == 0)
        data->map[data->player_location_y][data->player_location_x] = 'N';
}

int key_events(int keycode, t_data *data)
{
    int loc_y = 0;
    loc_y = data->player_location_y - data->first_line;

    printf("%i\n",data->look_degree);
    if (keycode == 13)
        move_up(data,loc_y);
    if (keycode == 1)
        move_down(data, loc_y);
    if (keycode == 0)
        move_left(data, loc_y);
    if (keycode == 2)
        move_right(data, loc_y);
    if (keycode == 124)
    {
        rotate_right(data);
        return(1);
    }
    if (keycode == 123)
    {
        rotate_left(data);
        return(1);
    }
    if (keycode == 53)
        xbutton(data);
    render(data);
    return(1);
}