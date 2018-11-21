#include <stdlib.h>
#include <stdio.h>

int 	*ft_range(int start, int end)
{
	int *arr;
	int eend;
	int i = 0;

	if (end > start)
		eend = end;
	


	if (!(arr = (int*)malloc(sizeof(int) * (eend - start + 1))))
		return (0);
	if (start <= end)
	{
		while (start <= end)
		{
			arr[i] = start;
			i++;
			start++;

		}
	}
	else if (end < start)
	{
		while (start > end)
		{
			arr[i] = start;
			start--;
			i++;
		}

	}

	return (arr);
}

int main(void)
{
	int i = 0;
	int *ptr;

	int start = 0;
	int end = 0;

	ptr = ft_range(start, end);
	if (start <= end)
	{
		while (start <= end)
		{
			printf("%d ", ptr[i]);
			start++;
			i++;
		}
	}
	else if (start > end)
	{
		while (start >= end)
		{
			printf("%d ", ptr[i]);
			i++;
			start--;
		}
	}
	printf("\n");

	return (0);
}