/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:33:01 by ejavier-          #+#    #+#             */
/*   Updated: 2025/07/26 00:48:20 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	winner(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	printf("==================================================\n");
	printf("|                  !!You won!!                    |\n");
	printf("| You found all the potions and enter the portal. |\n");
	printf("| You made %d moves, would you like to try again? |\n", data->counter);
	printf("================================================\n");
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}