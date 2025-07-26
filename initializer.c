/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:41:42 by ejavier-          #+#    #+#             */
/*   Updated: 2025/07/26 07:31:16 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_initializer_help(t_data *data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./assets/pleft.xpm";
	data->img->player_left = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./assets/p1.xpm";
	data->img->player_down = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./assets/pright.xpm";
	data->img->player_right = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	if (!data->img->player_left || !data->img->player_down)
		handle_error(data, "Error\nOne of Player files not found", 1);
	if (!data->img->player_right)
		handle_error(data, "Error\nPlayer right file not found", 1);
	relative_path = "./assets/background.xpm";
	data->img->background = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	if (!data->img->background)
		handle_error(data, "Error\nbackground file not found", 1);
}

void	ft_initializer(t_data *data, t_map *map)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	t_img	*img;

	data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		perror("Error\nmalloc failed\n");
		exit(EXIT_FAILURE);
	}
	data->img = img;
	relative_path = "./assets/pup.xpm";
	data->img->player_up = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	if (!data->img->player_up)
		handle_error(data, "Error\nPlayer up file not found", 1);
	ft_initializer_help(data);
	data->counter = 0;
	data->collected = 0;
}