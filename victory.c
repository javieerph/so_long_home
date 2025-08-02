/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:33:01 by ejavier-          #+#    #+#             */
/*   Updated: 2025/08/02 08:48:12 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	winner(t_data *data)
{
	ft_printf("===================================================\n");
	ft_printf("|                  !!You won!!                    |\n");
	ft_printf("| You found all the potions and enter the portal. |\n");
	ft_printf("| You made %d moves, would you like to try again? |\n",
		data->counter);
	ft_printf("===================================================\n");
	free_game(data);
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
