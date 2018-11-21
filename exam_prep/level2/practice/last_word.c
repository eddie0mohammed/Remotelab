#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	char array[1000];

	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		i--;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i--;
		while (argv[1][i] != ' ' && argv[1][i] != '\t' && i >= 0)
		{
			array[j] = argv[1][i];
			j++;
			i--;
		}
		j--;
		while (j >= 0)
		{
			// if (array[j] == '\0')
			// 	break;
			ft_putchar(array[j--]);
		}


	}
	ft_putchar('\n');

	return (0);
}