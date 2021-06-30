NAME = push_swap

RM = rm -rf

CC = gcc

FLAGS = -Wall -Wextra -Werror

FILES =	source/checkab.c \
		source/error_add.c \
		source/libft1.c \
		source/libft2.c \
		source/libft3.c \
		source/libft4.c \
		source/num_add.c \
		source/ops.c \
		source/sort_3_num.c \
		source/sort_6_num.c \
		source/sort_x_num.c


all:	$(NAME)

$(NAME):
		$(CC) $(FLAGS) push_swap.c $(FILES) -o $(NAME)

clean:
		rm $(NAME)

fclean: clean
		$(RM) all

re:	fclean all

.PHONY:	all clean fclean re
