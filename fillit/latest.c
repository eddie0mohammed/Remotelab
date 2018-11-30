#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int	validate_piece(char *buf, int ret)
{
	int count;
	int num_blocks;
	int i;
	int j;

	count = 0;
	i = 0;
	j = 0;
	int max = 19;
	int min = 0;
	num_blocks = (ret / 21) + 1;
	
	while (j < num_blocks)
	{
		while (i < max)
		{
			if (buf[i] == '#')
			{
				if (buf[i - 1] == '#')
					count++;
				if (buf[i + 1] == '#')
					count++;
				if (buf[i - 5] == '#' && (i - 5 >= min))
					count++;
				if (buf[i + 5] == '#' && (i + 5 <= max))
					count++;
			}
			i++;
		}
		if (count == 6 || count == 8)
		{
			printf("%d\n", count);
			max += 21;
			min += 21;
			count = 0;
		}
		else
		{
			printf("Error: Count != 6 || 8\n");
			return (-1);
		}
		j++;
	}
	//printf("%d\n",count);
	printf("num_blocks >>> %d\n", num_blocks);
	return (1);
}


int validate_blocks(char *buf, int ret)
{
	int num_dots;
	int num_hash;
	int i;

	num_dots = 0;
	num_hash = 0;
	i = 0;
	//printf("%d\n", ret);
	while (i <= ret)
	{
		if (i == ret && num_dots == 12 && num_hash == 4)
		{
			printf("Last Piece is also valid\n");
			break;
		}
		if (buf[i] == '.')
			num_dots++;
		else if(buf[i] == '#')
			num_hash++;
		else if (buf[i] == '\n' && buf[i + 1] == '\n')
		{
			if (num_dots == 12 && num_hash == 4)
			{
				printf("Valid Piece\n");
				i++;
			}
			else
			{
				printf("Invalid Piece\n");
				return (-1);
			}
			num_dots = 0;
			num_hash = 0;
		}
		i++;
	}
	//printf("%s", buf);
	//printf("%d\n" , i);
	validate_piece(buf, ret);
	return (1);
}
int helper(int ret, char *buf, int i, int j)
{
	while (i <= j)
    {
        if (buf[ret - 1] == '\n')
            return (-1);
        if (buf[i - 1] == '\0')
        {
            printf("No Errors\n");
            validate_blocks(buf, ret);
            return (1);
        }
        if (buf[i - 1] != '\n')
            return (-1);
        if (i == j && buf[i] != '\n' && buf[i] != '\0')
            return (-1);
        if (i == j && buf[i] == '\n')
        {
            i += 1;
            j += 21;
        }
        i += 5;
    }
	return (1);
}

int validate_file(int fd)
{
	char buf[547];
	int ret;
	int i;
	int j;
	int outcome;

	if ((ret = read(fd, buf, 546)) != -1)
		buf[ret] = '\0';
	j = 20;
	i = 5;
	outcome = helper(ret, buf, i, j);
	if (outcome == -1)
		return (-1);
	return (0);
}

int main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			validate_file(fd);
		}
		else
		{
			printf("Error: File Doesn's Exist\n");
		}
		close(fd);
	}
	else
	{
		printf("Error: No file as argument\n");
	}
	return 0;
}
