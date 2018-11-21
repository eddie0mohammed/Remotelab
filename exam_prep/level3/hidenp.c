#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (*argv[1] == '\0')
		{
			ft_putchar('1');
			ft_putchar('\n');
			return (0);
		}
		int i = 0;
		int j = 0;
		while(argv[1][i])
		{
			while (argv[2][j])
			{
				if (argv[1][i] == '\0')
				{
					ft_putchar('1');
					ft_putchar('\n');
					return (0);
				}
				if (argv[2][j] == argv[1][i])
					i++;
				j++;
			}
			i++;
		}
		ft_putchar('0');
	}
	ft_putchar('\n');
	return (0);
}