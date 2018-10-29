#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFF 1
int main(void)
{
	int	fd;
	int ret;
	char buf[BUFF + 1];

	fd = open("file1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("###failed to open");
		return (0);
	}
	else
	{
		printf("###successfully opened\n");

		while ((ret = read(fd, buf, BUFF)) != 0)
		{
			if (buf[0] == '\n')
			{
				printf("\n");

				break;
			}
			buf[ret] = '\0';
			printf("%c", buf[0]);

		}
		close(fd);
	}




	return (0);
}