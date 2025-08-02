/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:18:47 by ejavier-          #+#    #+#             */
/*   Updated: 2025/08/02 10:42:43 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_game(t_data *data)
{
    int i;

    if (data->img)
    {
        if (data->img->player_up)
            mlx_destroy_image(data->mlx, data->img->player_up);
        if (data->img->player_left)
            mlx_destroy_image(data->mlx, data->img->player_left);
        if (data->img->player_right)
            mlx_destroy_image(data->mlx, data->img->player_right);
        if (data->img->player_down)
            mlx_destroy_image(data->mlx, data->img->player_down);
        if (data->img->background)
            mlx_destroy_image(data->mlx, data->img->background);
        free(data->img);
		data->img = NULL;
    }
	if (data->map)
	{
    	if (data->map->map)
    	{
        	i = 0;
        	while (data->map->map[i])
            	free(data->map->map[i++]);
        	free(data->map->map);
        	data->map->map = NULL;
    	}
    	free(data->map);
    	data->map = NULL;
	}
	if (data->win)
	{
        mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
    }
}

void    ft_free_map(t_map *map)
{
    int i = 0;

    if (!map)
        return;

    if (map->map)
    {
        while (map->map[i])
        {
            free(map->map[i]);
            i++;
        }
        free(map->map);
    }
    free(map);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_exit(data);
	else if (keycode == 'w' || keycode == XK_Up)
		ft_move(data, 'y', UP);
	else if (keycode == 'a' || keycode == XK_Left)
		ft_move(data, 'x', LEFT);
	else if (keycode == 's' || keycode == XK_Down)
		ft_move(data, 'y', DOWN);
	else if (keycode == 'd' || keycode == XK_Right)
		ft_move(data, 'x', RIGHT);
	if (data->map->map[data->p_y][data->p_x] == 'E')
		winner(data);
	return (0);
}
