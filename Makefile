# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 19:04:26 by ejavier-          #+#    #+#              #
#    Updated: 2025/07/17 20:43:53 by ejavier-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)
NAME := so_long
CC := cc
CFLAGS := -Wall -Wextra -Werror
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

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(MLX_LIB):
	@make -C mlx

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	@make -C mlx clean

re: fclean all
