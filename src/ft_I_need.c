#include "cub3d.h"

void ft_map_long(t_data *data)
{
    int i;
    int diff;
    int max;

    i = data->first_line;
    diff = data->last_line - data->first_line;
    max = 0;
        while(i < data->last_line)
        {
            i++;
            if (max < (int)ft_strlen(data->map[i]))
                max = (int)ft_strlen(data->map[i]);
        }
        data->max_long = max;
}

void    ft_find_player(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'W' || data->map[i][j] == 'E')
            {
                data->player_location_x = j;
                data->player_location_y = i - data->first_line;
                break ;
            }
            j++;
        }
        i++;
    }
}

void    ft_ground_color(t_data *data)
{
    int i;

    i = -1;
    while (data->map[++i])
    {
        if (data->map[i][0] == 'C')
            break ;
    }
    //...
}

void    ft_sky_color(t_data *data)
{
    int i;

    i = -1;
    while (data->map[++i])
    {
        if (data->map[i][0] == 'F')
            break ;
    }
    //...
}

void ft_I_need(t_data *data)
{
    data->map_weight = data->last_line - data->first_line + 1;
    ft_map_long(data);
    ft_find_player(data);
    ft_sky_color(data);
    ft_ground_color(data);
    //ft_find_xpm(data);
}