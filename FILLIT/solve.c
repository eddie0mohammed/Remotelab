#include "header.h"

int	fits(t_board *bord, t_tet *tet, int row, int col)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - tet->row)
	{
		j = 0;
		while (j < 4 - tet->col)
		{
			if (tet->shape[tet->row + i][tet->col + j] == '#')
			{
				if (col + j >= bord->size || row + i >= bord->size || \
					(bord->board)[row + i][col + j])
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	add_tet(t_board *bord, int row, int col, t_tet *tet)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - tet->row)
	{
		j = 0;
		while (j < 4 - tet->col)
		{
			if (tet->shape[tet->row + i][tet->col + j] == '#')
				(bord->board)[row + i][col + j] = tet->letter;
			j++;
		}
		i++;
	}
	return (1);
}

int	delete_tet(t_board *bord, int row, int col, t_tet *tet)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - tet->row)
	{
		j = 0;
		while (j < 4 - tet->col)
		{
			if (tet->shape[tet->row + i][tet->col + j] == '#')
				(bord->board)[row + i][col + j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int	next_tet(t_board *bord, t_list *tetriminos)
{
	int row;
	int col;

	if (!tetriminos)
		return (1);
	row = 0;
	while (row < bord->size)
	{
		col = 0;
		while (col < bord->size)
		{
			if (fits(bord, tetriminos->content, row, col))	//check if piece fits on board with current board size
			{
				add_tet(bord, row, col, tetriminos->content);
				if (next_tet(bord, tetriminos->next))
					return (1);
				else
					delete_tet(bord, row, col, tetriminos->content);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	solve(t_board *bord, t_list *tetriminos)
{
	while (!next_tet(bord, tetriminos))
	{
		bord->size += 1;
	}
	return (1);
}
