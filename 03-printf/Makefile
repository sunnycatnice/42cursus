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

NAME =			libftprintf.a

CC = 			gcc

CFLAGS = 		-Wall -Wextra -Werror

LIB =			ar -crs

RM =			rm -rf

DIR_P_REQ = 	p_req

DIR_UTILS = 	utils

SRCS =			ft_printf.c \
				ft_check_modifiers.c

SRCS_SPECS  =	p_req_c.c \
				p_req_s.c \
				p_req_p.c \
				p_req_d.c \
				p_req_u.c \
				p_req_x.c \
				p_req_r.c

SRCS_UTILS =	ft_isdigit.c \
				ft_numlen_base.c \
				ft_unumlen_base.c \
				ft_ulnumlen_base.c \
				ft_putchar_fd.c \
				ft_putnbr_base_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putstrlen_fd.c \
				ft_putunbr_base_fd.c \
				ft_putunbr_fd.c \
				ft_simple_atoi.c \
				ft_strlen.c

SRCS_SPECS_PREFIX = $(addprefix ${DIR_SPECS}/, ${SRCS_SPECS})

SRCS_UTILS_PREFIX = $(addprefix ${DIR_UTILS}/, ${SRCS_UTILS})

OBJS = ${SRCS:.c=.o}

OBJS_SPECS = ${SRCS_SPECS_PREFIX:.c=.o}
 
OBJS_UTILS = ${SRCS_UTILS_PREFIX:.c=.o}

all: $(NAME)

.o.c: ${CC} ${CFLAGS} $<

$(NAME): ${OBJS} ${OBJS_SPECS} ${OBJS_UTILS}
	${LIB} ${NAME} ${OBJS} ${OBJS_SPECS} ${OBJS_UTILS}

clean:
	${RM} ${OBJS} ${OBJS_SPECS} ${OBJS_UTILS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
