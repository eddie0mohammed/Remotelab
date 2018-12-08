NAME = fillit
BASE = main \
	   helpers \
	   validate \
	   solve \
	   linked_list
SRC = $(addsuffix .c, $(BASE))
OBJ = $(addsuffix .o, $(BASE))
LIBFT = ./libft/libft.a
COMPILE = gcc -Wall -Wextra -Werror
INCLUDE = -I. -I./libft/ -I./get_next_line/
RED = \x1b[31m
GREEN = \x1b[32m
RESET = \x1b[0m

all: $(NAME)

$(NAME): $(LIBFT)
	@echo "$(GREEN)"Compiling Project"$(RESET)"
	@$(COMPILE) $(SRC) $(INCLUDE) $(LIBFT) -L ./libft
	@echo "$(GREEN)"Project Successfully Compiled"$(RESET)"

$(LIBFT):
	@echo "$(GREEN)"Compiling Libft"$(RESET)"
	@make -C ./libft

clean:
	@echo "$(RED)"Cleaning Files"$(RESET)"
	@make clean -C ./libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "$(RED)"Cleaning Library"$(RESET)"
	@make fclean -C ./libft
	@echo "$(RED)"Cleaning Executable"$(RESET)"
	@/bin/rm -f $(NAME)

re: fclean all
