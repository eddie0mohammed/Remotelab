#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rstr_capitalize(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && \
			(str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			ft_putchar(str[i] - 32);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	int i = 1;
	while (argv[i])
	{
		rstr_capitalize(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return 0;
}