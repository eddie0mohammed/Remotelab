#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i = 0;
	int j = 1;
	char array[128] = {0};
	if (argc == 3)
	{
		while (argv[j][i])
		{
			i = 0;
			while (argv[j][i])
			{
				if (array[(int)argv[j][i]] == 0)
				{
					array[argv[j][i]] = 1;
					ft_putchar(argv[j][i]);
				}
				i++;
			}
			j++;
		}
		
	}
	ft_putchar('\n');
	return (0);
}