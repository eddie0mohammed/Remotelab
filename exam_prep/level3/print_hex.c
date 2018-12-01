#include <unistd.h>

char	base[] = "0123456789abcdef";

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_atoi(char *str)
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

void	print_hex(int num)
{
	if (num >= 16)
		print_hex(num / 16);
	ft_putchar(base[num % 16]);

}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int num = ft_atoi(argv[1]);
		if (num == 0)
		{
			ft_putchar('0');
			ft_putchar('\n');
			return (0);
		}
		print_hex(num);



	}
	ft_putchar('\n');
	return 0;
}