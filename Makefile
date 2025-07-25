# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 19:04:26 by ejavier-          #+#    #+#              #
#    Updated: 2025/07/26 10:06:48 by ejavier-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)
NAME := so_long
CC := cc
CFLAGS := -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS := main.c check_valid_path.c helpers.c \
        initializer.c key_hook.c map.c \
        place_images.c validate_input.c victory.c \
        move.c
        
OBJS := $(SRCS:.c=.o)

ifeq ($(UNAME), Linux)
    INCLUDES := -Imlx
    MLX_FLAGS := -Lmlx -lmlx -lXext -lX11 -lm
    MLX_LIB := mlx/libmlx_Linux.a
else
    INCLUDES := -Imlx -I/opt/X11/include
    MLX_FLAGS := -Lmlx -lmlx -framework OpenGL -framework AppKit
    MLX_LIB := mlx/libmlx_Mac.a
endif

LIBFT = libft/libft.a

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(MLX_LIB) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C mlx

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(RM) $(OBJS)
	$(MAKE) -C mlx clean
	$(MAKE) -C libft clean
   
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C mlx clean
	$(MAKE) -C libft fclean

re: fclean all
