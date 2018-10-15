#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int x = 10;
	int y = 2;
	int *a;
	int *b;
	
	a = &x;
	b = &y;
	printf("%d %d\n", x, y);
	ft_swap(a, b);
	printf("%d %d\n", x, y);

	return (0);
}