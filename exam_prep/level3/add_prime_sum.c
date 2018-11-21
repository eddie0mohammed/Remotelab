#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int 	ft_atoi(const char *str)
{
	int i = 0;
	int n = 0;
	int sign = 1;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
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
	return (n * sign);
}

int		is_prime(int num)
{
	int i = 2;
	if (num < 0 || num == 0 || num == 1)
		return (0);
	if (num == 2 || num == 3)
		return (1);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// void	ft_putnbr(int num)
// {
// 	if (num > 10)
// 	{
// 		ft_putnbr(num / 10);
// 	}
// 	ft_putchar(num % 10 + '0');
// }

int		main(int argc, char **argv)
{
	int num = 0;
	if (argc == 2 && (num = ft_atoi(argv[1])) > 0)
	{
		int i = 2;
		int sum = 0;
		while (i <= num)
		{
			if (is_prime(i))
				sum += i;
			i++;
		}
		printf("%d\n", sum);



	}
	else
	{
		ft_putchar('0');
		ft_putchar('\n');
	}

	return (0);
}











