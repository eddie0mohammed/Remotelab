#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "includes/header.h"

void	initialize(char board[104][104])
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
			board[i][j] = '.';
			j++;
		}
		i++;
	}
}

// void	print_board(char board[104][104])
// {
// 	int i = 0;
// 	int j = 0;

// 	while (i < 104)
// 	{
// 		j = 0;
// 		while (j < 104)
// 		{
// 			ft_putchar(board[i][j]);
// 			j++;
// 		}
// 		ft_putchar('\n');
// 		i++;
// 	}
// }

////////////////////////////////////////////////////////////////
void	calculate_width_height(char *buf)
{
	int width;
	int height;
	int i;
	int count;

	width = 1;
	height = 1;
	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#')
				count++;
			if (buf[i - 1] == '#')
				count++;
			if (buf[i + 5] == '#')
				count++;
			if (buf[i - 5] == '#')
				count++;
		}
		if (buf[i] == '#' && buf[i + 1] == '#')
			width++;
		if (buf[i] == '#' && buf[i + 5] == '#')
			height++;
		i++;
	}
	if (count == 8)
	{
		width--;
		height--;
	}
	printf("width = %d\n", width);
	printf("height = %d\n", height);
	printf("count = %d\n", count);
	printf("======================\n");
	free(buf);
}

//////////////////////////////////////////////////////////////////
char	*get_w_h_of_all_file(char *buf)
{
	int i = 0;
	//int blocks = 0;
	char *block;
	int ret = 0;
	int num_blocks;
	int j = 0;
	int max = 19;
	int min = 0;
	int piece_count = 1;
	while (buf[ret])
		ret++;
	ret++;
	num_blocks = (ret / 21 + 1);
	printf("ret: %d\n", ret);
	printf("num_blocks: %d\n", num_blocks);


	while (j < num_blocks)
	{
		if(!(block = (char*)malloc(sizeof(char) * 21)))
			return (NULL);
		while (min < max)
		{
			block[i] = buf[min];
			i++;
			min++;
		}
		block[i] = '\0';
		
		printf("\npiece %d:\n", piece_count);
		piece_count++;
		ft_putstr(block);
		printf("\n");
		calculate_width_height(block);
		j++;
		max += 21;
		min += 2;
		i = 0;
	}
	return (block);
}


//////////////////////////////////////////////////////////////////

void	ft_continue(char *buf)
{
	char board[104][104];

	initialize(board);
	//ft_putstr(buf);
	//print_board(board);
	//calculate_width_height(buf);
	get_w_h_of_all_file(buf);
}

int main(int argc, char **argv)
{
	int fd;
	char *buf;
	//char *list;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			if((buf = validate_file(fd)) == NULL) 
			{
				ft_putstr("Error in File\n");
				return (0);
			}
			else
			{
				ft_putstr("\nVerification SUCCESS\n");
				ft_continue(buf);
			}
		}
		else
			ft_putstr("Error: File Doesn't Exist\n");
		free(buf);
		close(fd);
	}
	else
		ft_putstr("usage : fillit file_name\n");
	return (0);
}
