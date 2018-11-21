#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int i = 0;
	int *array;
	int eend = end;
	if (eend < 0)
		eend = -(eend);
	if (!(array = (int*)malloc((sizeof(int) * (eend - start + 1)))))
		return (NULL);
	// if (start > end)
	// {
	// 	int temp = end;
	// 	end = start;
	// 	start = temp;
	// }
	if (start <= end)
	{
		while (start <= end)
		{
			array[i] = start;
			start++;
			i++;
		}
	}
	else if (start > end)
	{
		while (start >= end)
		{
			array[i] = start;
			start--;
			i++;
		}
	}
	return (array);

}

int main(void)
{
	int i = 0;
	int start = 0;
	int end = 0;
	int *array = ft_range(start, end);
	if (start < end)
	{
		while (start <= end)
		{
			printf("%d ", array[i]);
			i++;
			start++;
		}
	}
	else
	{
		while (start >= end)
		{
			printf("%d ", array[i]);
			i++;
			start--;
		}

	}

	printf("\n");
	return (0);
}