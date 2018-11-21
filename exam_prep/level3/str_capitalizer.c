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
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	if (str[0] >= 'A' && str[0] <= 'Z')
			ft_putchar(str[0]);
	else if (str[0] == ' ' || str[0] == '\t')
		ft_putchar(str[0]);
	i = 1;
	while (str[i])
	{
		if ((str[i - 1] == ' ' || str[i - 1] == '\t'))
			ft_putchar(str[i]);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar(str[i] + 32);
		else
			ft_putchar(str[i]);
		i++;
 
	}
}

int	main(int argc, char  **argv)
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




	return (0);
}