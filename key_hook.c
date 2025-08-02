/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:18:47 by ejavier-          #+#    #+#             */
/*   Updated: 2025/08/02 02:54:59 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double_pointer(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
		i++;
	while (i >= 0)
		free(data->map->map[i--]);
	free(data->map->map);
	free(data->img);
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
