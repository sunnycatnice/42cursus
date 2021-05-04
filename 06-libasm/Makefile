NAME = libasm.a

AS = @nasm

ASFLAGS = -fmacho64

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

run: $(NAME)
	gcc -Wall -Wextra -Werror -L. -lasm main.c grafic.c main.h
	./a.out

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean run

.PHONY: run clean fclean re
