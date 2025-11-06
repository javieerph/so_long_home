/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:26:45 by ejavier-          #+#    #+#             */
/*   Updated: 2025/11/06 04:22:26 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_borders(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->size_y / IMG_H))
	{
		if ((int)ft_strlen(data->map->map[y]) != data->size_x / IMG_W)
			handle_error(data, "Error\nmap has to be rectangular\n", 1);
		x = 0;
		while (x < (data->size_x / IMG_W))
		{
			if (data->map->map[y][x] != '0' && data->map->map[y][x] != '1' &&
				data->map->map[y][x] != 'C' && data->map->map[y][x] != 'P' &&
				data->map->map[y][x] != 'E')
				handle_error(data, "Error\n'0','1','C','P','E' are valid\n", 1);
			else if (((y == 0) || (x == 0)) && data->map->map[y][x] != '1')
				handle_error(data, "Error\n T or L not covered by walls\n", 1);
			else if ((y == (data->size_y / IMG_H - 1)
					|| x == (data->size_x / IMG_W - 1))
				&& data->map->map[y][x] != '1')
				handle_error(data, "Error\nB or R not covered by walls\n", 1);
			x++;
		}
		y++;
	}
}

static void	ft_check_content(t_data *data)
{
	int	y;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	data->map->potions = 0;
	y = 0;
	while (data->map->map && data->map->map[y])
	{
		exit += ft_count_c(data->map->map[y], 'E');
		player += ft_count_c(data->map->map[y], 'P');
		data->map->potions += ft_count_c(data->map->map[y], 'C');
		y++;
	}
	if (player != 1)
		handle_error(data, "Error\nThere is an error in map/\n", 1);
	if (exit == 0 || exit > 1)
		handle_error(data, "Error\nonly valid map if there is one exit\n", 1);
	if (data->map->potions == 0)
		handle_error(data, "Error\nNo potion to collect\n", 1);
}

static void	ft_open_and_allocate(t_data *data, char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
	{
		perror("Error\nFailed to open file");
		exit(EXIT_FAILURE);
	}
	if (!data->map->map)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		close(*fd);
		exit(EXIT_FAILURE);
	}
}

static void	ft_read_map(t_data *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		data->map->map[i++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	data->map->map[i] = NULL;
	data->size_y = i * IMG_H;
	data->size_x = ft_strlen(data->map->map[0]) * IMG_W;
	close(fd);
}

void	validate_input(t_data *data, char **argv, int argc)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map_file>\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_open_and_allocate(data, argv[1], &fd);
	ft_read_map(data, fd);
	if (data->size_x / IMG_H == data->size_y / IMG_H)
		handle_error(data, "Error\nWrong map dimensions", 1);
	ft_check_content(data);
	ft_check_borders(data);
}
