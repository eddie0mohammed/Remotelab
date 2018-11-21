#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int 	ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int n = 0;

	while((str[i] >= '9' && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (sign * n);
}

void	ft_putnbr(int num)
{
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int num = ft_atoi(argv[1]);
		if (num > 2147483647 || (9 * num) > 2147483647)
			return (0);
		int i = 1;
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(num);
			write(1, " = ", 3);
			ft_putnbr(i * num);
			if (i == 9)
				break;
			ft_putchar('\n');
			i++;
		}

	}
	ft_putchar('\n');
	
	return 0;
}