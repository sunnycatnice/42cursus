# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmangola <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 13:49:42 by dmangola          #+#    #+#              #
#    Updated: 2021/03/05 14:31:43 by dmangola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -I Add the directory dir to the list of directories to be searched for header files
# -L Searches the library when linking
# make -C flag makes you go to the appropriate path and do the asked command
# %.o: %.c - "to build a file named <something>.o, which depends on <something.c>"
# -o $@ - name of the target of the rule
#  $< - the first prerequisite of the rule (gcc -c -o $@ $< = gcc -c -o foo.o foo.c)
#  $^ - all prerequisites of the rule

NAME = cub3D

LIBFT_PATH = ./libs/libft/
MINILIBX_PATH = ./libs/mlx/minilibx_mms_20200219

SRCS = $(wildcard ./srcs/input/*.c) $(wildcard ./srcs/game/*.c) cub3D.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -O3 -c -Wall -Wextra -Werror
MLX_FLAGS = -I ./libs/mlx/minilibx_mms_20200219 -L ./libs/mlx/minilibx_mms_20200219 -lmlx -framework OpenGL -framework Appkit
LIBFT_FLAGS = -I ./libs/libft -L ./libs/libft ./libs/libft/*.c
INCLUDE = cub3d.h

all: libft_make minilibx_make $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) libft.a libmlx.dylib -I./ $(OBJS) -o $(NAME)

libft_make:
		make -C $(LIBFT_PATH) all
		cp ./libs/libft/libft.a libft.a

libft_fclean:
		make -C $(LIBFT_PATH) fclean
		rm -f libft.a

minilibx_make:
		make -C $(MINILIBX_PATH) all
		cp ./libs/mlx/minilibx_mms_20200219/libmlx.dylib libmlx.dylib

minilibx_clean:
		make -C $(MINILIBX_PATH) clean
		rm -f libmlx.dylib && rm -f libmlx.a

clean:
	rm -f $(NAME)

fclean: clean minilibx_clean libft_fclean
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY:	all libft_make libft_fclean minilibx_make minilibx_clean clean fclean re
