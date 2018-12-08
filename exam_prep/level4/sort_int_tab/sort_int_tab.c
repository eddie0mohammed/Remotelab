#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int j = 0;
	int temp;

	if (!tab || size == 0)
		return ;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int main(void)
{
	int size = 6;
	int tab[6] = {5, 4, 6, 2, 1, 0};
	int i = 0;
	sort_int_tab(tab, 6);
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}