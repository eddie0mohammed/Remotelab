#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(void)
{
	char z = 'z';
	while (z >= 'a')
	{
		if (z % 2 == 0)
		{
			ft_putchar(z);
		}
		else
			ft_putchar(z - 32);
		z--;
	}
	ft_putchar('\n');

	return (0);
}