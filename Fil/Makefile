NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS = libft.c main.c tetrimino.c solve.c lst.c

all: $(NAME)
	
$(NAME):
	gcc $(FLAGS) -I. -c $(SRCS)
	gcc $(FLAGS) $(SRCS:.c=.o) -o $(NAME)

clean:
	rm -f $(SRCS:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all
