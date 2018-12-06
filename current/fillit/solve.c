#include "header.h"

int fits(t_board *bord, t_tetri *tetri, int row, int column)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - tetri->row)
	{
		j = 0;
		while (j < 4 - tetri->column)
		{
			if (tetri->shape[tetri->row + i][tetri->column + j] == '#')
			{
				if (column + j >= bord->size || row + i >= bord->size || (bord->board[row + i][column + j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int add_tetri(t_board *bord, int row, int column, t_tetri *tetri)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - tetri->row)
	{
		j = 0;
		while (j < 4 - tetri->column)
		{
			if (tetri->shape[tetri->row + i][tetri->column + j] == '#')
				(bord->board)[row + i][column + j] = tetri->alpha;
			j++;
		}
		i++;
	}
	return (1);
}

int delete_tetri(t_board *bord, int row, int column, t_tetri *tetri)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - tetri->row)
	{
		j = 0;
		while (j < 4 - tetri->column)
		{
			if (tetri->shape[tetri->row + i][tetri->column + j] == '#')
				(bord->board)[row + i][column + j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int next_tetri(t_board *board, t_list *tetriminos)
{
	int row;
	int column;

	if (!tetriminos)
		return (1);
	row = 0;
	while (row < board->size)
	{
		column = 0;
		while (column < board->size)
		{
			if (fits(board, tetriminos->content, row, column))
			{
				add_tetri(board, row, column, tetriminos->content);
				if (next_tetri(board, tetriminos->next)) 	//recursive
					return (1);
				else
					delete_tetri(board, row, column, tetriminos->content);
			}
			column++;
		}
		row++;
	}
	return (0);
}



int	solve(t_board *board, t_list *tetriminos)
{
	while (!next_tetri(board, tetriminos))
		board->size += 1;
	return (1);

}