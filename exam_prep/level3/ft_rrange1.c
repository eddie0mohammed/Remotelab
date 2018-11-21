#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int *arr;

	int i = 0;
	int size;
	if (end < start)
	{
		size = start - end;
	}
	else
		size = end - start;
		
	if (!(arr = (int*)malloc(sizeof(int) * (size + 1))))
		return (0);
	if (end >= start)
	{
		while (end >= start)
		{
			arr[i] = end;
			end--;
			i++;

		}
	}
	else if (end <= start)
	{
		while (end <= start)
		{
			arr[i] = end;
			end++;
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
	int end = -5;
	ptr = ft_rrange(start, end);
	if (end >= start)
	{
		while (end >= start)
		{
			printf("%d ", ptr[i]);
			i++;
			end--;
		}
	}
	else if (end <= start)
	{
		while (end <= start)
		{
			printf("%d ", ptr[i]);
			i++;
			end++;
		}
	}
	printf("\n");
	return (0);
}