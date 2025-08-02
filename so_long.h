/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:51:59 by ejavier-          #+#    #+#             */
/*   Updated: 2025/08/02 10:11:54 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

/* ********** defines ********** */

# define IMG_W 34
# define IMG_H 44
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

/* ********** Main and key_hook ********** */

void	free_game(t_data *data);
int		ft_key_hook(int keycode, t_data *data);
void	handle_error(t_data *data, char *str, int num);
int		ft_exit(t_data *data);
void	check_filename(char *file_name);
void    ft_free_map(t_map *map);

/* ********** Map functions ********** */

void	window_size(t_data *data, char **argv);
void	create_map(t_data *data);

/* ********** Place images ********** */

void	put_background(t_data *data);
void	put_object(t_data *data, char *relative_path);
void	put_player(t_data *data);

/* ********** Initializer ********** */

void	ft_initializer(t_data *data, t_map *map);

/* ********** Check_valid_path ********** */

int		e_valid_path(t_data *data, int x, int y, char **visited);
int		c_valid_path(t_data *data, int x, int y, char **visited);
void	check_path_of_collectables(t_data *data, int x, int y);
void	check_path(t_data *data);

/* ********** Helpers ********** */

void	find_px_py(t_data *data);
void	free_double_p(char ***str);
void	calloc_failure(char *str);
int		ft_count_c(char *s, char c);

/* ********** Validate_input ********** */

void	validate_input(t_data *data, char **argv, int argc);

/* ********** Victory ********** */

void	winner(t_data *data);

/* ********** Move functions ********** */

void	ft_move(t_data *data, char pos, int dir);

#endif
