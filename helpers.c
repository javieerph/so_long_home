/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:16:40 by ejavier-          #+#    #+#             */
/*   Updated: 2025/07/25 22:54:57 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
  
void	find_px_py(t_data *data)  
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
			}
			x++;
		}
	y++;
	}
}

void	free_double_p(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
		i++;
	i--;
	while (i >= 0)
		free((*str)[i--]);
	free((*str));
}

void	calloc_failure(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	ft_count_c(char *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!s)
		return (-1);
	while (s && s[i])
	{
		if (s[i++] == c)
			x++;
	}
	return (x);
}