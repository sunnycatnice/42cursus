# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 00:25:55 by bde-luca          #+#    #+#              #
#    Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME =				minishell

#Compiler
CC = 				gcc
CFLAGS = 			-L /Users/$(USER)/goinfre/.test/.brew/opt/readline/lib -I/goinfre/$(USER)/.test/.brew/opt/readline/include -lreadline -Qunused-arguments -Wall -Wextra -Werror -g
CFLAG = 			-c
OFLAG =				-o
IFLAG =				-I
TCFLAG =			-ltermcap

#Make
MAKE = 				make -C
MAKE_CLEAN = 		make clean -C
MAKE_FCLEAN = 		make fclean -C
MAKE_NORM =			make norm -C

#Norm
NORM =				norminette

#Shell
MKDIR =				mkdir -p
CP =				cp
RM =				rm -rf

#Directories
SRCDIR = 			./srcs
OBJDIR =  			./objs
INCDIR = 			./includes
# INCLUDE =			-I /Users/$(USER)/goinfre/.test/.brew/opt/readline/include
#LIBS = 				-L /Users/$(USER)/goinfre/.test/.brew/opt/readline/lib -lreadline
LIBFTDIR = 			./libft

LIBFT = 			libft.a

FILES =				pwd.c \
					utils.c \
					echo.c \
					echo_utils.c \
					cd.c \
					env.c \
					export.c \
					parse.c \
					splitter.c \
					searchandlaunch.c \
					signal_handler.c \
					main.c \
					node.c \
					node_utils.c \
					dollaro.c \
					export_utils.c \
					add_data.c \
					unset.c \
					more_utils.c \
					cd_utils.c	\
					cd_utils2.c	\
					ft_init.c \
					graphic.c \
					ft_split_and_count.c \
					ft_pipex_split.c \
					pipex_bonus.c \
					pipex_error.c \
					pipex_parsers.c \
					pipex_utils.c \
					pipex_utils2.c \
					parser_quotes.c \
					discriminator.c \
					exit.c \
					execute.c \
					utils_fd.c \
					utils_pipe.c \
					setting.c \
					execve.c \
					signal.c \
					error.c \
					utils_env.c \
					ft_realloc_doublestr.c \
					execve2.c \
					main_pipe.c \
					escaper.c \
					tokenizer.c \
					lexer.c \
					parser.c \
					utils_get_parser.c \
					converter.c \
					utils_converter.c \
					utils_free.c \
					utils_string.c \
					utils_set_parser.c \
					ft_redirect.c \
					exec_pipes.c \
					pipe_utils.c \
					execute_cmd.c \
					utils_2.c \
					pipes.c \
					pipes2.c \
					more_more_utils.c \
					redirection.c \
					more_redirection.c \
					here_doc.c \
					utils_3.c \
					pipes3.c \
					signal_daniele.c \
					more_more_more_utils.c \
					unset_utils.c

SRCS =	$(foreach FILE, $(FILES), $(shell find $(SRCDIR) -name $(FILE)))

OBJS =	$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.c=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(IFLAG) $(INCDIR) $(CFLAG) $(OFLAG) $@ $< 

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(TCFLAG) $(OBJS) $(LIBFT)  $(OFLAG) $(NAME)

$(LIBFT):
	@$(MAKE) $(LIBFTDIR)
	@$(CP) $(LIBFTDIR)/$(LIBFT) .

norm:
	@$(NORM) $(SRCDIR)
	@$(NORM) $(INCDIR)
	@$(MAKE_NORM) $(LIBFTDIR)

clean:
	@$(RM) $(OBJDIR) $(OBJS) $(LIBFT)
	@$(RM) ./libft.a
	@$(MAKE_CLEAN) $(LIBFTDIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ./libft.a
	@$(MAKE_FCLEAN) $(LIBFTDIR)

re: fclean all

.PHONY: all norm clean fclean re
