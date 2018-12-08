#include "header.h"

int		delete_tet(t_board *brd, int row, int column, t_tetri *tet)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - tet->row)
	{
		j = 0;
		while (j < 4 - tet->column)
		{
			if (tet->shape[tet->row + i][tet->column + j] == '#')
				(brd->board)[row + i][column + j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		add_tet(t_board *brd, int row, int column, t_tetri *tet)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - tet->row)
	{
		j = 0;
		while (j < 4 - tet->column)
		{
			if (tet->shape[tet->row + i][tet->column + j] == '#')
				(brd->board)[row + i][column + j] = tet->alpha;
			j++;
		}
		i++;
	}
	return (1);
}

int		fits(t_board *brd, t_tetri *tet, int row, int column)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - tet->row)
	{
		j = 0;
		while (j < 4 - tet->column)
		{
			if (tet->shape[tet->row + i][tet->column + j] == '#')
			{
				if (column + j >= brd->size || row + i >= brd->size
					|| (brd->board)[row + i][column + j])
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		next_tet(t_board *brd, t_list *tetriminos)
{
	int row;
	int col;

	if (!tetriminos)
		return (1);
	row = 0;
	while (row < brd->size)
	{
		col = 0;
		while (col < brd->size)
		{
			if (fits(brd, tetriminos->content, row, col))
			{
				add_tet(brd, row, col, tetriminos->content);
				if (next_tet(brd, tetriminos->next))
					return (1);
				else
					delete_tet(brd, row, col, tetriminos->content);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int		solve(t_board *brd, t_list *tetriminos)
{
	while (!next_tet(brd, tetriminos))
		(brd->size)++;
	return (1);
}
