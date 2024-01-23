# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 20:51:08 by shikwon           #+#    #+#              #
#    Updated: 2023/08/28 23:09:38 by shikwon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
LBSD = -lbsd
RM = rm -rf
SRCS= main.c utils.c \
	environment_check.c extension_check.c\
	gnl/get_next_line.c gnl/get_next_line_utils.c \
	libftprintf/ft_printf.c libftprintf/ft_putchar.c \
	libftprintf/ft_putnbr.c libftprintf/ft_putstr.c \
	libftprintf/ft_puthex.c \
	libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strdup.c \
	libft/ft_split.c libft/ft_calloc.c libft/ft_memset.c \
	libft/ft_memcpy.c libft/ft_substr.c libft/ft_strnstr2.c \
	read_map.c check_path.c load_map.c \
	load_graphic.c event.c \

INC_DIR= ./

OBJECTS= $(SRCS:.c=.o)

MLX = minilibx-linux/libmlx.a

all: $(NAME)

$(MLX):
	make -C minilibx-linux

$(NAME): $(OBJECTS) $(MLX)
	$(CC) $(CFLAGS) -Iminilibx-linux/ $(SRCS) -lX11 -lm -lXext -Lminilibx-linux/ -lXrandr -lmlx -o $(NAME) $(LBSD)

clean:
	$(RM) $(OBJECTS)
	make clean -C minilibx-linux

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean bonus
