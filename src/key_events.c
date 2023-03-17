#include "cub3d.h"

int move_up(t_data *data)
{
    return 0;
}

int move_down(t_data *data)
{
    return 0;
}

int move_left(t_data *data)
{
    return 0;
}


int move_right(t_data *data)
{
    return 0;
}

void    rotate_left(t_data *data)
{

}

void    rotate_right(t_data *data)
{

}

void    see_map(t_data *data)
{
    int i = data->first_line;
    int j = data->last_line;
    while (i <= j)
        printf("%s",data->map[i++]);
}

int key_events(int keycode, t_data *data)
{
    if (keycode == 13)
        move_up(data);
    if (keycode == 1)
        move_down(data);
    if (keycode == 0)
        move_left(data);
    if (keycode == 2)
        move_right(data);
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