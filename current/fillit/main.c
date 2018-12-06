#include "header.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	initialize_board(char board[104][104])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 104)
	{
		j = 0;
		while (j < 104)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_board(char board[104][104], int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board[i][j] != 0)
				ft_putchar(board[i][j]);
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_board	brd;
	char	buf[20];
	t_list	*tetriminos;
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit file_name\n");
		return (0);
	}
	initialize_board(brd.board);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	else if (!fd)
	{
		ft_putstr("usage: ./fillit file_name\n");
		return (0);
	}
	tetriminos = ft_create_list(fd, buf);
	if (!tetriminos)
	{
		ft_putstr("Error\n");
		return (0);
	}
	brd.size = ft_get_nearest_square(ft_get_size(tetriminos));
	if (!solve(&brd, tetriminos))
	{
		ft_putstr("Error\n");
		return (0);
	}
	print_board(brd.board, brd.size);


	return (0);
}