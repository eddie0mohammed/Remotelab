#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int 	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		int arr[128] = {0};
		char *s1 = argv[1];
		char *s2 = argv[2];

		while (s2[i])
		{
			arr[(int)s2[i]] = 1;
			i++;
		}
		i = 0;
		while (s1[i])
		{
			if (arr[(int)s1[i]] == 1)
			{
				ft_putchar(s1[i]);
				arr[(int)s1[i]] = 0;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}