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

SRC = cub3d.c

MINILIBX_PATH = ./minilibx
LIBFT_PATH = ./libft

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -O3 -Wall -Wextra -Werror
MLXFLAGS = -I ./minilibx -L ./minilibx -lmlx -framework OpenGL -framework Appkit
UTILS = ./utils/*.c
SRCS = ./srcs/input/*.c && ./srcs/game/*.c
INCLUDE = cub3d.h

all: minilibx_make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(UTILS) $(SRC) $(SRCS) libmlx.a -I./ $(OBJS) -o $(NAME)

libft_make:
		make -C $(LIBFT_PATH) all
		cp ./libft/libft.a libft.a

libft_clean:
		make -C $(LIBFT_PATH) clean

libft_fclean:
		make -C $(LIBFT_PATH) fclean
		rm -f libft.a

minilibx_make:
		make -C $(MINILIBX_PATH) all
		cp ./minilibx/libmlx.a libmlx.a

minilibx_clean:
		make -C $(MINILIBX_PATH) clean
		rm -f libmlx.a

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY:	all minilibx_make minilibx_clean clean fclean re
