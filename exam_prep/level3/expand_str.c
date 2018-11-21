#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2 && argv[1])
	{
		int i = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
			{
				ft_putchar(argv[1][i]);
				i++;
			}
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
			if (argv[1][i] != '\0')
			{
				write(1, "   ", 3);
			}

		}
	}
	ft_putchar('\n');
	return (0);
}