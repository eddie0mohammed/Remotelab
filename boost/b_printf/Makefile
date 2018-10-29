# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medun <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 15:36:42 by medun             #+#    #+#              #
#    Updated: 2018/09/17 21:17:44 by medun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES_C = b_print_add.c b_print_char.c b_print_hex.c b_print_int.c \
		  b_print_octal.c b_print_string.c b_print_uint.c \
		  b_printf.c

FILES_O = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I. -c $(FILES_C)
	ar rc $(NAME) $(FILES_O)
	ranlib $(NAME)

clean:
	rm -f $(FILES_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
