#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main (int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	if (argc >= 2)
	{
		while (argv[argc -1][i])
		{
			ft_putchar(argv[argc -1][i]);
			i++;
		}

	}
	ft_putchar('\n');

	return (0);
}