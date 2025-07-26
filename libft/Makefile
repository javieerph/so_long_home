# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 19:40:11 by ejavier-          #+#    #+#              #
#    Updated: 2025/07/26 00:09:44 by ejavier-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c ft_atoi.c\
ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c ft_bzero.c\
ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c ft_calloc.c\
ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c ft_isalnum.c\
ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c ft_isalpha.c\
ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c ft_isascii.c\
ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c get_next_line.c

OBJS = $(SRCS:.c=.o)

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
