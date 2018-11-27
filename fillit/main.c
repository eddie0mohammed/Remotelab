#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int validate_blocks(char *buf, int ret)
{
	int num_blocks;

	num_blocks = ()


	
	// printf("%d\n", ret);
	// printf("%s", buf);
	// printf("\n");
	return (1);
}


int validate_file(int fd)
{
	char buf[547];
	int ret;
	int i;
	int num_blocks;

	if ((ret = read(fd, buf, 546)) != -1)
		buf[ret] = '\0';

	//num_blocks = (ret / )
	//check if new lines are at the right spot;
	int j = 20;
	i = 5;
	while (i <= j)
	{
		if (buf[ret - 1] == '\n')	//check if new line at the end of file
		{
			printf("ERROR. New line AT THE END\n");
			return (-1);
		}
		if (buf[i - 1] == '\0')	// ending condition
		{
			printf("No Errors\n");
			validate_blocks(buf, ret);
			return (1);
		}
		if (buf[i - 1] != '\n')	// check for new line in each block
		{
			printf("ERROR. New line MISSING IN block\n");
			return (-1);
		}
		if (i == j && buf[i] != '\n' && buf[i] != '\0')	//check for new line AFTER each block
		{
			printf("Error. No new line AFTER block\n");
			return (-1);
		}	
		if (i == j && buf[i] == '\n')
		{
			i += 1;
			j += 21;
		}
		i += 5;
	}
	return (0);
}



int main(int argc, char const *argv[])
{
	int fd;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
			validate_file(fd);

		close(fd);
	}
	else
	{
		printf("Error: No file  as argument\n");
	}
	return 0;
}