#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

int 	ft_atoi(const char *str)
{
	int i = 0;
	int n = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	if (argc == 2)
	{
		if (9 * ft_atoi(argv[1] <= 2147483647))
		{
			int i = 1;
			while (i <= 9)
			{
				ft_putnbr(i);
				write(1, " x ", 3);
				ft_putnbr(ft_atoi(argv[1]));
				write(1, " = ");
				ft_putnbr(i * (ft_atoi(argv[1])));
			}

		}
	}

	return (0);
}