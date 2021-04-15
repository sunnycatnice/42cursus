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

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -framework OpenGL -framework AppKit -o

MAKE = make -C
MAKE_CLEAN = make clean -C
MAKE_FCLEAN = make fclean -C

NORM_CFSH = norminette -R CheckForbiddenSourceHeader
NORM_CD = norminette -R CheckDefine

CP = cp
RM = rm -rf

DIR_INCLUDES = includes

DIR_LIBS = libs
DIR_LIBFT = libft
DIR_MLX = mlx/minilibx_mms_20200219
LIBFT = $(addprefix $(DIR_LIBS)/, $(DIR_LIBFT))
LIBMLX = $(addprefix $(DIR_LIBS)/, $(DIR_MLX))

MYLIB = libft.a
MLXLIB = libmlx.dylib

DIR_SRCS = srcs
DIR_INPUT = input
DIR_GAME = game

SRCS_ROOT = 	cub3d.c

SRCS_INPUT =	input_graphic.c		\
				input_manager.c		\
				ft_get_col_tex.c	\
				ft_get_resolution.c	\
				ft_get_texture.c	\
				input_list_matrix.c	\
				input_check_arg.c	\
				input_check_err.c	\
				input_error.c		\
				input_free.c		\
				input_init.c		\
				input_msg.c			\
				input_control_correct.c \
				input_check_width.c	\

SRCS_GAME =		game_manager.c		\
				game_init.c			\
				game_map.c			\
				game_flags.c		\
				game_utils.c		\
				game_keys.c			\

SRCS_INPUT_PREFIX_1 = $(addprefix $(DIR_INPUT)/, $(SRCS_INPUT))
SRCS_GAME_PREFIX_1 = $(addprefix $(DIR_GAME)/, $(SRCS_GAME))
SRCS_TMP += $(SRCS_ROOT) $(SRCS_INPUT_PREFIX_1) $(SRCS_GAME_PREFIX_1)
SRCS = $(addprefix $(DIR_SRCS)/, $(SRCS_TMP))

OBJS = $(SRCS:.c=.o)

.o.c: $(CC) $(CFLAGS) $<

all: $(NAME)

$(NAME): $(MYLIB) $(MLXLIB) $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(NAME) $(OBJS) $(MYLIB) $(MLXLIB)

$(MYLIB):
	$(MAKE) $(LIBFT)
	$(CP) $(LIBFT)/$(MYLIB) .

$(MLXLIB):
	$(MAKE) $(LIBMLX)
	$(CP) $(LIBMLX)/$(MLXLIB) .

norminette:
	$(NORM_CFSH) $(SRCS)
	$(NORM_CD) $(DIR_INCLUDES)/*

clean:
	$(RM) $(OBJS) $(MYLIB) 
	$(MAKE_CLEAN) $(LIBMLX)
	$(MAKE_CLEAN) $(LIBFT)

fclean: clean
	$(RM) $(NAME) $(MLXLIB)
	$(MAKE_FCLEAN) $(LIBFT)

re: fclean all

.PHONY: all norminette clean fclean re
