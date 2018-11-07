#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int 	i;
	char	array[256];
	int 	j;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		while(argv[1][i])
			i++;
		i--;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i--;
		while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
		{
			array[j] = argv[1][i];
			i--;
			j++;
		}
		j--;
		while (j >= 0)
		{
			ft_putchar(array[j]);
			j--;
		}



	}
	ft_putchar('\n');

	return (0);
}