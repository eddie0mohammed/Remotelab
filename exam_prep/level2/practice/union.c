#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	if(argc == 3)
	{
		int i = 0;
		int hash[128] = {0};

		while (argv[2][i])
		{
			hash[(int)argv[2][i]] = 1;
			i++;
		}
		i = 0;
		while (argv[1][i])
			hash[(int)argv[1][i++]] = 1;
		i = 0;
		while (argv[1][i])
		{
			if (hash[(int)argv[1][i]] == 1)
				ft_putchar(argv[1][i]);
			i++;
		}


	}
	ft_putchar('\n');
	return (0);
}