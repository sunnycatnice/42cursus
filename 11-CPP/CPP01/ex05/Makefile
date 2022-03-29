# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 00:25:55 by dmangola          #+#    #+#              #
#    Updated: 2022/03/29 18:37:48 by dmangola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME =				karen2

#Compiler
CC = 				clang++
CFLAGS = 			-Wall -Wextra -Werror -std=c++98
CFLAG = 			-c
OFLAG =				-o
IFLAG =				-I

#Make
MAKE = 				make -C

#Shell
MKDIR =				mkdir -p
CP =				cp
RM =				rm -rf

#Directories
SRCDIR = 			./srcs
OBJDIR =  			./objs
INCDIR = 			./includes

FILES =				main.cpp \
					karen.cpp \

SRCS =	$(foreach FILE, $(FILES), $(shell find $(SRCDIR) -name $(FILE)))

OBJS =	$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.cpp=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(IFLAG) $(INCDIR) $(CFLAG) $(OFLAG) $@ $< 

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(OFLAG) $(NAME)

clean:
	@$(RM) $(OBJDIR) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
