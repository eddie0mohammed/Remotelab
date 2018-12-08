#include "header.h"
#include <stdlib.h>

void	initialize_p(t_piece *p)
{
	p->num = 0;	// number of '#' in piece
	p->connection = 0;	// number of neighboring '#'
	p->left = 4;	// distance to first '#' in piece : initially 4
	p->top = 4;		// distance to first '#' in piece from top. initially 4
}

int		calculate_connection(char *str, int position)
{
	int count;

	count = 0;
	if (position % 5 > 0 && str[position - 1] == '#')	// > 0 - same block
		count++;
	if (position % 5 < 4 && str[position + 1] == '#')
		count++;
	if (position / 5 > 0 && str[position - 5] == '#')
		count++;
	if (position / 5 < 4 && str[position + 5] == '#')
		count++;
	return (count);
}

void	modify_p(t_piece *p, char *str, int i, int j)
{
	if (i % 5 < p->left)
		p->left = i % 5;
	if (j < p->top)
		p->top = j;
	p->connection += calculate_connection(str, i);
	p->num += 1;	//increase number of hashes in block by 1
}

t_tet	*store_tet(char *str, int top, int left, int count)
{
	t_tet	*tet;
	int		i;
	int		j;
	char	*alpha;

	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = 0;
	j = 0;
	if (!(tet = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	tet->row = top;	// position of top-most '#' in piece
	tet->col = left;	// position of left-most '#' in piece
	tet->letter = alpha[count];	// assign a letter to the shape
	while (i < 20)
	{
		if (!(i != 0 && i % 5 == 4))  // turns 5*4 into 4*4 excluding '\n';
			tet->shape[i / 5][i % 5] = str[i]; //[row][column]
		i++;
	}
	return (tet);
}

t_tet	*create_tet(char *str, int count)
{
	int		i;
	int		j;
	t_piece	p;	//num, connection, left, top

	initialize_p(&p);
	i = 0;
	j = 0;
	while (i < 20)
	{
		if (i % 5 == 4)	// check for new lines at the end of each line in block
		{
			if (str[i] != '\n')
				return (NULL);
			j++;	// increase line count by 1;
		}
		else if (!((str[i] == '#') || (str[i] == '.'))) // check for any other piece other than '#' or '.'
			return (NULL);
		else if (str[i] == '#')
			modify_p(&p, str, i, j); // modify left-most and top-most '#':
		i++;
	}
	if (p.num == 4 && (p.connection == 6 || p.connection == 8))
		return (store_tet(str, p.top, p.left, count));
	return (NULL);
}
