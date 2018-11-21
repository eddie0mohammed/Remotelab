#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	str_capitalize(char *str)
{
	int i = 0;
	if (str[i] == '\0')
		return ;
	while (str[i])	//to lower_case
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
		{
			ft_putchar(str[i]);
			i++;
		}
		if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0')
			ft_putchar(str[i] - 32);
		else
		{
			if (str[i] == '\0')
				break;
			ft_putchar(str[i]);
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	int i = 1;
	while (i < argc)
	{
		str_capitalize(argv[i]);
		i++;
		ft_putchar('\n');

	}
	return 0;
}