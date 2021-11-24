# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 16:57:18 by dmangola          #+#    #+#              #
#    Updated: 2021/11/24 19:28:04 by dmangola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipes

HPATH = -Iincludes

CC = gcc

FLAGS = -Wall -Wextra -Werror

DIR_SRCS = srcs
DIR_MINILIBFT= minilib
DIR_PHILO = program
DIR_OBJS = objs
CURRENT_FOLDER = $(shell pwd)
OBJS_PATH = $(addprefix $(CURRENT_FOLDER)/, $(DIR_OBJS))

MINILIBFT_PATH = $(addprefix $(DIR_SRCS)/, $(DIR_MINILIBFT))
PHILO_PATH = $(addprefix $(DIR_SRCS)/, $(DIR_PHILO))

MINILIBFT_FILES =	ft_split.c \
					ft_strjoin.c \

PHILO_FILES	=		pipex_bonus.c \
					pipex_parsers.c \
					pipex_utils.c \
					pipex_utils2.c \
					pipex_error.c \

SRCS_MINILIBFT = $(addprefix $(MINILIBFT_PATH)/, $(MINILIBFT_FILES))
SRCS_PHILO = $(addprefix $(PHILO_PATH)/, $(PHILO_FILES))
SRCS = $(SRCS_MINILIBFT) $(SRCS_PHILO)

OBJS_FILES = $(PHILO_FILES:.c=.o) $(MINILIBFT_FILES:.c=.o)
OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS_FILES))

all: $(NAME)

$(OBJS) : $(SRCS)
	-@$(CC) $(FLAGS) $(SRCS)
	mv *.o $(DIR_OBJS)

$(NAME) : $(OBJS)
	@echo Compiling: $(NAME)
	@$(CC) $(FLAGS) $(HPATH) $(OBJS) -o $(NAME)
	@echo Compiled successfully!

clean:
	@echo Deleting objects files...
	@rm -f $(OBJS)
	@echo Deleting done!

fclean: clean
	@echo Deleting $(NAME)...
	@rm $(NAME)
	@rm -rf *.o
	@echo Deleting done!

re: fclean all

.PHONY: all clean fclean re
