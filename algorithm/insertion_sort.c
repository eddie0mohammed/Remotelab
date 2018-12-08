#include <stdio.h>

void	swap(int *a, int *b)
{
	int x;

	x = *a;
	*a = *b;
	*b = x;
}

void insertion_sort(int *array, int num)
{
	int i;
	int j;

	i = 1;
	while (i < num)
	{
		j = i;
		while ((j > 0) && (array[j] < array[j - 1]))
		{
			swap(&array[j], &array[j - 1]);
			j--;
		}
		i++;
	}
}

int main(void)
{
	int array[] = {9, 1, 3, 2, 8, 4, 7, 5, 6, 0};

	insertion_sort(array, 10);
	int i = 0;
	while (i < 10)
	{
		printf("%d ", array[i]);
		i++;
	}
	return (0);
}