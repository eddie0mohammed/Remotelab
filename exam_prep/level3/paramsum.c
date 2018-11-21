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

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		write(1, "0\n", 2);
		return (0);
	}

	(void)argv;
	ft_putnbr(argc - 1);
	ft_putchar('\n');
	return 0;
}