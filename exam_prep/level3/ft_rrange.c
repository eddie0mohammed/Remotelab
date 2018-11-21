#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int i = 0;
	int *array;
	int eend = end;
	if (eend < 0)
		eend = -(eend);
	if (!(array = (int*)malloc(sizeof(int) * (eend - start + 1))))
		return (NULL);
	if (end > start)
	{
		while (end >= start)
		{
			array[i] = end;
			end--;
			i++;
		}
	}
	else if (end < start)
	{
		while (end <= start)
		{
			array[i] = end;
			end++;
			i++;
		}
	}
	return (array);

}

int main(void)
{
	int i = 0;
	int start = 0;
	int end = -3;
	int *arr = ft_rrange(start, end);
	if (start < end)
	{
		while (start <= end)
		{
			printf("%d ", arr[i]);
			start++;
			i++;
		}
	}
	else if (start > end)
	{
		while (start >= end)
		{
			printf("%d ", arr[i]);
			start--;
			i++;
		}
	}
	printf("\n");
	return (0);
}