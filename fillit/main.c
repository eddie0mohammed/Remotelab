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

void	ft_continue(char *buf)
{
	char board[104][104];

	initialize(board);
	//ft_putstr(buf);
	//print_board(board);
	
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
