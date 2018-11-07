#include <stdio.h>

int		max(int *tab, unsigned int len)
{
	int i;
	int maxi;

	i = 0;
	maxi = tab[0];
	if (!tab || len == 0)
		return (0);
	while (i < len)
	{
		if (tab[i] > maxi)
			maxi = tab[i];
		i++;
	}
	return (maxi);
}

int		main(void)
{
	int tab[4] = {1};
	int i = 0;
	while (i < 4)
	{
		printf("%d", tab[i]);
		i++;

	}
	printf("\n%d\n", max(tab, 0));

	return (0);
}