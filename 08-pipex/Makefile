# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmangola <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 18:40:21 by dmangola          #+#    #+#              #
#    Updated: 2021/06/12 17:41:13 by dmangola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HPATH = -Iincludes

CC = gcc

FLAGS = -Wall -Wextra -Werror

DIR_SRCS = srcs
DIR_MINILIBFT= minilibft
DIR_PIPEX = pipex

MINILIBFT_PATH = $(addprefix $(DIR_SRCS)/, $(DIR_MINILIBFT))
PIPEX_PATH = $(addprefix $(DIR_SRCS)/, $(DIR_PIPEX))

MINILIBFT_FILES = ft_putstr_fd.c \
				   ft_strcat.c \
				   ft_strcmp.c \

PIPEX_FILES  = pipex.c \
			   utils.c \

SRCS_MINILIBFT = $(addprefix $(MINILIBFT_PATH)/, $(MINILIBFT_FILES))
SRCS_PIPEX = $(addprefix $(PIPEX_PATH)/, $(PIPEX_FILES))
SRCS = $(SRCS_MINILIBFT) $(SRCS_PIPEX)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(SRCS)
	echo Compiling: $(NAME)
	$(CC) $(FLAGS) $(HPATH) $(SRCS) -o $(NAME)
	echo Compiled successfully

clean:
	echo Deleting objects files...
	@rm -f $(OBJ)
	echo Deleting done

fclean: clean
	echo Deleting $(NAME)
	@rm -f $(NAME)
	echo Deleting done !

re: fclean all

.PHONY: all clean fclean re
