/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:43:01 by ejavier-          #+#    #+#             */
/*   Updated: 2025/07/26 07:14:34 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_player_move(t_data *data, char position, int direction)
/* will put the correct orientation of the spaceship on the screen */
{
	if (position == 'y' && direction == UP)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_up,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	if (position == 'x' && direction == LEFT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_left,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	if (position == 'y' && direction == DOWN)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_down,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	if (position == 'x' && direction == RIGHT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_right,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
}

static void	ft_collect(t_data *data, char pos, int dir)
/* will collect the collectables
** will remove them from the map-struct as well as the screen */
{
	data->collected++;
	data->map->map[data->p_y][data->p_x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->p_x * IMG_W), (data->p_y * IMG_H));
	ft_player_move(data, pos, dir);
}

void	ft_move(t_data *data, char pos, int dir)
{
	printf("here\n");
	int old_x = data->p_x;
	int old_y = data->p_y;
	
	if (pos == 'y' && data->map->map[data->p_y + dir][data->p_x] != '1' &&
		(data->map->map[data->p_y + dir][data->p_x] != 'E' ||
		data->collected == data->map->potions))
		data->p_y += dir;
	else if (pos == 'x' && data->map->map[data->p_y][data->p_x + dir] != '1' &&
		(data->map->map[data->p_y][data->p_x + dir] != 'E' ||
		data->collected == data->map->potions))
		data->p_x += dir;
	else if ((pos == 'y' && data->map->map[data->p_y + dir][data->p_x] == 'E') ||
		(pos == 'x' && data->map->map[data->p_y][data->p_x + dir] == 'E'))
	{
		if (data->collected != data->map->potions)
			printf("Collect all collectibles before leaving\n");
		return;
	}
	else
		return;
	
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		old_x * IMG_W, old_y * IMG_H);
	
	ft_player_move(data, pos, dir);
	
	if (data->map->map[data->p_y][data->p_x] == 'C')
		ft_collect(data, pos, dir);
	
	mlx_do_sync(data->mlx);
	printf("You moved %d times.\n", ++data->counter);	
}