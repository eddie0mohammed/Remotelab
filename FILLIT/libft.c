#include "header.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	initialize_board(char board[104][104])
{
	int	i;
	int	j;

	i = 0;
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
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (board[row][col])
				ft_putchar(board[row][col]);
			else
				ft_putchar('.');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
