#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int i;
	int x;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				x = (argv[1][i] - 'a' + 1);
				while (x != 0)
				{
					ft_putchar(argv[1][i]);
					x--;
				}
			}
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				x = (argv[1][i] - 'A' + 1);
				while (x != 0)
				{
					ft_putchar(argv[1][i]);
					x--;
				}

			}
			else
				ft_putchar(argv[1][i]);
			i++;

		}

	}
	ft_putchar('\n');
	return (0);
}