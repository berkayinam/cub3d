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

void    player_look_degree(t_data *data, int i, int j)
{
    //karakter hangi yöne bakıyorsa başlangıç için X = -1 Y = 0 gibi değer belirle. posX = -1 gibi. 
    //şimdilik bu fonksiyon böyle kalsın
    if(data->map[i][j] == 'N')
        data->look_pos = 0;
    if(data->map[i][j] == 'W')
        data->look_pos = 270;
    if(data->map[i][j] == 'E')
        data->look_pos = 90;
    if(data->map[i][j] == 'S')
        data->look_pos = 180;
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
                player_look_degree(data, i, j);
                break ;
            }
            j++;
        }
        i++;
    }
}

void    ft_ground_color(t_data *data)
{
    /*int     i;
    char    *f_str;
    char    **f_str_RGB;
    int     r;
    int     g;
    int     b;
    int		rgbfx;

    i = -1;
    while (data->map[++i])
        if (ft_strchr(data->map[i], 'C') != NULL)
            break;
    f_str = ft_strchr(data->map[i], 'C');
    f_str_RGB = malloc(sizeof(char) * 4);
    f_str = ft_strtrim(f_str,"FC ");
    f_str_RGB = ft_split(f_str,',');
    f_str_RGB[3] = 0;
    r = ft_atoi(f_str_RGB[0]);
    g = ft_atoi(f_str_RGB[1]);
    b = ft_atoi(f_str_RGB[2]);
    rgbfx = ft_atoi(ft_strdup(ft_strjoin(ft_strjoin(ft_itoa(r),ft_itoa(g)), ft_itoa(b))));
	*/
}



void    ft_sky_color(t_data *data, int base)
{
    /*int     i;
    char    *f_str;
    char    **f_str_RGB;
    int     r;
    int     g;
    int     b;
    int		rgbfx;

    i = -1;
    while (data->map[++i])
        if (ft_strchr(data->map[i], 'F') != NULL)
            break;
    f_str = ft_strchr(data->map[i], 'F');
    f_str_RGB = malloc(sizeof(char) * 4);
    f_str = ft_strtrim(f_str,"FC ");
    f_str_RGB = ft_split(f_str,',');
    f_str_RGB[3] = 0;
    r = ft_atoi(f_str_RGB[0]);
    g = ft_atoi(f_str_RGB[1]);
    b = ft_atoi(f_str_RGB[2]);
    rgbfx = ft_atoi(ft_strdup(ft_strjoin(ft_strjoin(ft_itoa(r),ft_itoa(g)), ft_itoa(b))));
	*/
}

void ft_I_need(t_data *data)
{
    data->map_weight = data->last_line - data->first_line + 1;
    ft_map_long(data);
    ft_find_player(data);
    ft_sky_color(data, 16);
    ft_ground_color(data);
    //ft_find_xpm(data);
}