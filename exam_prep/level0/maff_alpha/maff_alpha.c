#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(void)
{
	char a = 'a';
	while (a <= 'z')
	{
		if (a % 2 == 0)
		{
		
			ft_putchar(a - 32);
		}
		else
			ft_putchar(a);
		a++;
	}

	return (0);
}