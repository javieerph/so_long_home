/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:51:59 by ejavier-          #+#    #+#             */
/*   Updated: 2025/07/13 18:28:24 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

/* ********** defines ********** */

# define IMG_W 32
# define IMG_H 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UARROW 126
# define LARROW 123
# define DARROW 125
# define RARROW 124
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

/* ***** struct to store the different images ***** */

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
}				t_img;

/* ***** struct to create the map and keep track of the contents ***** */

typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		potions;
}				t_map;

/* ***** struct to hand all of my programms data between functions ***** */

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}				t_data;

/* ********** Check map ********** */

int	e_valid_path(t_data *data, int x, int y, char **visited);
int	c_valid_path(t_data *data, int x, int y, char **visited);
static void	fill_visited(char ***visited, t_data *data);
void	check_path_of_collectables(t_data *data, int x, int y);
void	check_path(t_data *data);
void	find_px_py(t_data *data);
void	free_double_p(char ***str);
void	calloc_failure(char *str);

#endif