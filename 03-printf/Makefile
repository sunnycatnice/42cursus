# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmangola <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 11:42:52 by dmangola          #+#    #+#              #
#    Updated: 2021/01/28 12:03:37 by dmangola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	check_fun.c \
			ft_nbrlen.c \
			ft_putstr.c \
			ft_putwidth.c \
			ft_printf.c \
			p_req_c.c \

OBJS	= $(SRCS:.c=.o)
CC		= gcc
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= .
LIBFT	= ./libft/libft.a

%.o: %.c $(LIBFT)
		${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

$(NAME) : ${OBJS} $(LIBFT)
		cp	$(LIBFT) $(NAME)
		${LIBC} $(NAME) $(OBJS)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all bonus clean fclean re .c.o
