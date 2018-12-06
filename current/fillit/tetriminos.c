#include "header.h"
#include <stdlib.h>

void	initialize_p(t_piece *p)
{
	p->num_hash = 0;
	p->connection = 0;
	p->left = 4;
	p->top = 4;
}

int 	calculate_connection(char *str, int position)
{
	int count;

	count = 0;
	if ((position % 5 > 0) && str[position - 1] == '#')
		count++;
	if ((position % 5 < 4) && str[position + 1] == '#')
		count++;
	if ((position / 5 > 0) && str[position - 5] == '#')
		count++;
	if ((position / 5 < 4) && str[position + 5] == '#')
		count++;
	return (count);
}

void	modify_p(t_piece *p, char *str, int i, int j)
{
	if (i % 5 < (p->left))
		p->left = i % 5;
	if (j < p->top)
		p->top = j;
	p->connection = p->connection + calculate_connection(str, i);
	p->num_hash += 1;
}

t_tetri	*store_tetri(char *str, int top, int left, int num_pieces)
{
	t_tetri 	*tetri;
	int 		i;
	int 		j;
	char		*alphabet;

	i = 0;
	j = 0;
	alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (!(tetri = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	tetri->row = top;
	tetri->column = left;
	tetri->alpha = alphabet[num_pieces];
	while (i < 20)
	{
		if (!(i != 0 && i % 5 == 4)) //condition to remove the '\n' at the end of the shape(each line) in the buf
			tetri->shape[i / 5][i % 5] = str[i];
		i++;
	}
	return (tetri);
}

t_tetri	*ft_create_tetri(char *str, int num_pieces)
{
	int 	i;
	int 	j;
	t_piece	p;
	t_tetri	*tetri;

	initialize_p(&p);
	i = 0;
	j = 0;
	while (i < 20)
	{
		if (i % 5 == 4)		//check for new lines at the end of each block
		{
			if (str[i] != '\n')
				return (NULL);
			j++;
		}
		else if (!((str[i] == '#') || (str[i] == '.'))) // check if each piece is either '#' || '.'
			return (NULL);
		else if (str[i] == '#')
		{
			modify_p(&p, str, i, j);
		}
		i++;
	}
	if (p.num_hash == 4 && (p.connection == 8 || p.connection == 6))
	{
		tetri = store_tetri(str, p.top, p.left, num_pieces);
		return (tetri);
	}
	return (NULL);
}