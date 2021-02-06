# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmangola <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 11:42:52 by dmangola          #+#    #+#              #
#    Updated: 2021/01/28 12:03:37 by dmangola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= $(wildcard ./p_requests/*.c) $(wildcard ./utils/*.c) ft_printf.c main.c

OBJ		= $(SRC:.c=.o)
CC = gcc
CFLAGS	= -c -Wall -Wextra -Werror
HEADER	= ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(OBJ)

re: fclean all