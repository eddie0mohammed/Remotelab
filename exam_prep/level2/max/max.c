#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	unsigned int 	i;
	int				max;

	i = 0;

	max = tab[i];
	if (!tab || len == 0)
		return (0);
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);

}

int	main(int argc, char const *argv[])
{
	int	tab[]= {0};

	printf("%d\n", max(tab, 0));
	return 0;
}