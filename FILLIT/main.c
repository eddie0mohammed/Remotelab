#include "header.h"
#include <fcntl.h>

int		get_size(t_list *tetriminos)	// calculate the size of list
{
	int	count;

	count = 0;
	while (tetriminos)
	{
		count++;
		tetriminos = tetriminos->next;
	}
	return (count);
}

int		get_nearest_square(int size)	// calculate the starting size of the board
{
	int	i;

	i = 2;
	while ((i * i) < (size * 4)) // (root)(pieces * 4)
	{
		i++;
	}
	return (i);
}

int		eerror(int x)
{
	if (x)
		ft_putstr("usage: ./fillit [file_name]\n");
	else
		ft_putstr("error\n");
	return (0);
}

int		main(int argc, char **argv)
{
	t_board	b;
	char	buf[20];	//each block consists of 20 chars
	t_list	*tetriminos;
	int		fd;

	if (argc != 2)
		return (eerror(1));
	initialize_board(b.board);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (eerror(0));
	tetriminos = create_list(fd, buf);	//linked list containing all info and shape for tetrimino
	if (!tetriminos)
		return (eerror(0));
	b.size = get_nearest_square(get_size(tetriminos)); //starting size of the board
	if (!solve(&b, tetriminos))
		return (eerror(0));
	print_board(b.board, b.size);
	return (0);
}
